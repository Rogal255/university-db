#include "../Database.hpp"
#include "../DatabaseToFile.hpp"
#include "../EmployeeRandomBuilder.hpp"
#include "../Person.hpp"
#include "../PersonBuilderDirector.hpp"
#include "../StudentRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>
#include <memory>
#include <optional>
#include <string>
#include <vector>

class DatabaseSearchTest : public ::testing::Test {
protected:
    void SetUp() override { jsonHandler.loadFromFile(db, "assets/databaseTest"); }
    Database db;
    DatabaseToFile jsonHandler;
};

TEST_F(DatabaseSearchTest, searchBySurnameTest) {
    auto vectorOfMazurs = db.searchBySurname("Mazur");
    ASSERT_EQ(vectorOfMazurs.size(), 2);
    const std::string& mazur1 = vectorOfMazurs[0]->getSurname();
    ASSERT_EQ(vectorOfMazurs[0]->getSurname(), "Mazur");
    ASSERT_EQ(vectorOfMazurs[1]->getSurname(), "Mazur");
    ASSERT_TRUE(vectorOfMazurs[0]->getName() == "Martyna" || vectorOfMazurs[0]->getName() == "Jan");
    ASSERT_TRUE(vectorOfMazurs[1]->getName() == "Martyna" || vectorOfMazurs[1]->getName() == "Jan");
    ASSERT_TRUE(vectorOfMazurs[0]->getPersonalID() == "60081877821"
                || vectorOfMazurs[0]->getPersonalID() == "86050172252");
    ASSERT_TRUE(vectorOfMazurs[1]->getPersonalID() == "60081877821"
                || vectorOfMazurs[1]->getPersonalID() == "86050172252");
    auto emptyVector = db.searchBySurname("Nazwisko");
    ASSERT_TRUE(emptyVector.empty());
}

TEST_F(DatabaseSearchTest, searchByPersonalIDTest) {
    auto person = db.searchByPersonalID("83022065334");
    ASSERT_TRUE((*person)->getName() == "Tymoteusz");
    ASSERT_TRUE((*person)->getSurname() == "Kubiak");
    person = db.searchByPersonalID("83022065335");
    ASSERT_FALSE(person);
}

class DatabaseSortTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (std::size_t i {0}; i < numberOfEmployees; ++i) {
            db.addPerson(director.create());
        }
        director.changeBuilder(&studentBuilder);
        for (std::size_t i {0}; i < numberOfStudents; ++i) {
            db.addPerson(director.create());
        }
    }
    Database db;
    DatabaseToFile jsonHandler;
    std::size_t numberOfEmployees {10};
    std::size_t numberOfStudents {40};
    EmployeeRandomBuilder employeeBuilder;
    StudentRandomBuilder studentBuilder;
    PersonBuilderDirector director {&employeeBuilder};
    nlohmann::json data;
};

TEST_F(DatabaseSortTest, sortBySurnameTest) {
    db.sortBySurname();
    jsonHandler.saveToFile(db, "tmp");
    std::ifstream fileStream("tmp.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    fileStream >> data;
    fileStream.close();
    std::remove("tmp.json");
    for (std::size_t i {1}; i <= data.size() - 1; ++i) {
        ASSERT_TRUE(data[i - 1]["surname"] <= data[i]["surname"]);
    }
}

TEST_F(DatabaseSortTest, sortByPersonalIDTest) {
    db.sortByPersonalID();
    jsonHandler.saveToFile(db, "tmp");
    std::ifstream fileStream("tmp.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    fileStream >> data;
    fileStream.close();
    std::remove("tmp.json");
    for (std::size_t i {1}; i <= data.size() - 1; ++i) {
        ASSERT_TRUE(data[i - 1]["id"] <= data[i]["id"]);
    }
}

TEST_F(DatabaseSortTest, sortBySalaryTest) {
    db.sortBySalary();
    jsonHandler.saveToFile(db, "tmp");
    std::ifstream fileStream("tmp.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    fileStream >> data;
    fileStream.close();
    std::remove("tmp.json");
    for (std::size_t i {1}; i <= data.size() - 1; ++i) {
        ASSERT_TRUE(data[i - 1]["salary"] >= data[i]["salary"]);
    }
}

class DatabaseMiscTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (std::size_t i {0}; i < numberOfEmployees; ++i) {
            db.addPerson(director.create());
        }
        director.changeBuilder(&studentBuilder);
        for (std::size_t i {0}; i < numberOfStudents; ++i) {
            db.addPerson(director.create());
        }
    }
    Database db;
    std::size_t numberOfEmployees {10};
    std::size_t numberOfStudents {40};
    EmployeeRandomBuilder employeeBuilder;
    StudentRandomBuilder studentBuilder;
    PersonBuilderDirector director {&employeeBuilder};
};

TEST_F(DatabaseMiscTest, changeSalaryTest) {
    // Having Person* changing salary is much easier than through Database class but for purpose of this test I use
    // both. User would have access only to interface provided by hypothetical Application class.
    std::string id1 = "60081877821";
    std::string id2 = "70060853997";
    std::string found = id1;
    auto person {db.searchByPersonalID(id1)};
    if (!person) {
        person = db.searchByPersonalID(id2);
        found = id2;
        if (!person) {
            throw std::logic_error("Logic error in changeSalaryTest - PersonalID not found");
        }
    }
    if ((*person)->getSalary()) {
        std::size_t newSalary {123};
        ASSERT_TRUE(db.changeSalary(found, newSalary));
        ASSERT_TRUE(*(*person)->getSalary() == newSalary);
    } else {
        throw std::logic_error("Logic error in changeSalaryTest - person found is not an employee");
    }
}

TEST_F(DatabaseMiscTest, deleteByIndexTest) {
    ASSERT_FALSE(db.deleteByIndex(10'001));
    nlohmann::json data;
    DatabaseToFile jsonHandler;
    jsonHandler.saveToFile(db, "tmp");
    std::ifstream fileStream("tmp.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    fileStream >> data;
    fileStream.close();
    std::remove("tmp.json");
    std::size_t indexToDelete {0};
    std::string personalID;
    bool found {false};
    for (std::size_t i {0}; i < numberOfEmployees + numberOfStudents; ++i) {
        if (data[i].contains("index")) {
            indexToDelete = data[i]["index"];
            personalID = data[i]["id"];
            found = true;
            break;
        }
    }
    if (!found) {
        throw std::logic_error("Student not found in deleteByIndexTest");
    }
    ASSERT_TRUE(db.deleteByIndex(indexToDelete));
    ASSERT_FALSE(db.searchByPersonalID(personalID));
}

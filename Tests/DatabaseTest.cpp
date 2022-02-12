#include "../Database.hpp"
#include "../DatabaseToFile.hpp"
#include "../EmployeeRandomBuilder.hpp"
#include "../Person.hpp"
#include "../PersonBuilderDirector.hpp"
#include "../StudentRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
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

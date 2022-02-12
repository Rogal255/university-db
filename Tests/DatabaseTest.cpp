#include "../Database.hpp"
#include "../DatabaseToFile.hpp"
#include "../EmployeeRandomBuilder.hpp"
#include "../Person.hpp"
#include "../PersonBuilderDirector.hpp"
#include "../StudentRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>
#include <fstream>
#include <gtest/gtest.h>
#include <memory>
#include <set>
#include <string>
#include <vector>

class DatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        nlohmann::json data_;
        DatabaseToFile dbFromFile;
        dbFromFile.loadFromFile(db, "assets/databaseTest");
    }
    Database db;
};

TEST_F(DatabaseTest, searchBySurnameTest) {
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
}

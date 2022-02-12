#include "../EmployeeManualBuilder.hpp"
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

class RandomBuilderTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ifstream fileStream("assets/data.json");
        if (!fileStream.is_open()) {
            throw std::runtime_error("Cannot read file");
        }
        fileStream >> data_;
    }
    PersonBuilderDirector director;
    nlohmann::json data_;
};

TEST_F(RandomBuilderTest, namesTest) {
    constexpr std::size_t testCases {50};
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    std::set<std::string> femaleNames;
    std::set<std::string> maleNames;

    for (const auto& name : data_["femaleNames"]) {
        femaleNames.emplace(name);
    }
    for (const auto& name : data_["maleNames"]) {
        maleNames.emplace(name);
    }

    for (uint8_t i {0}; i < testCases; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(static_cast<uint8_t>(ptr->getGender()) < 2 && static_cast<uint8_t>(ptr->getGender()) >= 0);
        if (ptr->getGender() == Gender::Female) {
            ASSERT_TRUE(femaleNames.contains(ptr->getName()));
        } else if (ptr->getGender() == Gender::Female) {
            ASSERT_TRUE(maleNames.contains(ptr->getName()));
        }
    }
}

TEST_F(RandomBuilderTest, surnamesTest) {
    constexpr std::size_t testCases {50};
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    std::set<std::string> femaleSurnames;
    std::set<std::string> maleSurnames;

    for (const auto& name : data_["femaleSurnames"]) {
        femaleSurnames.emplace(name);
    }
    for (const auto& name : data_["maleSurnames"]) {
        maleSurnames.emplace(name);
    }

    for (uint8_t i {0}; i < testCases; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(static_cast<uint8_t>(ptr->getGender()) < 2 && static_cast<uint8_t>(ptr->getGender()) >= 0);
        if (ptr->getGender() == Gender::Female) {
            ASSERT_TRUE(femaleSurnames.contains(ptr->getSurname()));
        } else if (ptr->getGender() == Gender::Female) {
            ASSERT_TRUE(maleSurnames.contains(ptr->getSurname()));
        }
    }
}

TEST_F(RandomBuilderTest, addressTest) {
    constexpr std::size_t testCases {50};
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    std::set<std::string> streets;
    std::set<std::string> cities;

    for (const auto& name : data_["streets"]) {
        streets.emplace(name);
    }
    for (const auto& name : data_["cities"]) {
        cities.emplace(name);
    }

    for (uint8_t i {0}; i < testCases; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(streets.contains(ptr->getAddress().street));
        ASSERT_TRUE(cities.contains(ptr->getAddress().city));
        ASSERT_TRUE(ptr->getAddress().country == "Polska");
        auto flat {std::stoul(ptr->getAddress().flat)};
        ASSERT_TRUE(flat > 0 && flat <= 300);
        auto building {std::stoul(ptr->getAddress().building)};
        ASSERT_TRUE(building > 0 && building <= 100);
        std::string zip = ptr->getAddress().zip;
        ASSERT_TRUE(zip.size() == 6);
        ASSERT_TRUE(zip[2] == '-');
        ASSERT_TRUE(std::count_if(zip.cbegin(), zip.cend(), [](unsigned char c) { return std::isdigit(c); }) == 5);
    }
}

TEST_F(RandomBuilderTest, personalIDTest) {
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    std::size_t femaleCounter {0};
    std::size_t maleCounter {0};
    bool femaleOverflow {false};
    bool maleOverflow {false};
    while (!femaleOverflow || !maleOverflow) {
        auto ptr = director.create();
        if (ptr->getGender() == Gender::Female) {
            femaleCounter++;
            if (femaleCounter > data_["femaleIDs"].size()) {
                femaleOverflow = true;
                ASSERT_TRUE(ptr->getPersonalID().empty());
                continue;
            }
            ASSERT_TRUE(ptr->getPersonalID() == data_["femaleIDs"][femaleCounter - 1]);
            continue;
        }
        if (ptr->getGender() == Gender::Male) {
            maleCounter++;
            if (maleCounter > data_["maleIDs"].size()) {
                maleOverflow = true;
                ASSERT_TRUE(ptr->getPersonalID().empty());
                continue;
            }
            ASSERT_TRUE(ptr->getPersonalID() == data_["maleIDs"][maleCounter - 1]);
            continue;
        }
    }
}

TEST_F(RandomBuilderTest, studentBuilderTest) {
    constexpr std::size_t testCases {50};
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    for (uint8_t i {0}; i < testCases; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(ptr->getIndex());
        ASSERT_TRUE(*(ptr->getIndex()) >= 0 && *(ptr->getIndex()) < 10'000);
    }
}

TEST_F(RandomBuilderTest, employeeBuilderTest) {
    constexpr std::size_t testCases {50};
    EmployeeRandomBuilder employeeBuilder;
    director.changeBuilder(&employeeBuilder);
    for (uint8_t i {0}; i < testCases; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(ptr->getSalary());
        ASSERT_TRUE(*(ptr->getSalary()) >= 3000 && *(ptr->getSalary()) <= 20000);
    }
}

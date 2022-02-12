#include "../Database.hpp"
#include "../DatabaseToFile.hpp"
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
#include <string>
#include <vector>

TEST(StudentRandomBuilder, randomStudentGeneration) {
    EmployeeRandomBuilder employeeBuilder;
    PersonBuilderDirector director(&employeeBuilder);
    nlohmann::json data_;
    std::ifstream fileStream("assets/data.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot read file");
    }
    fileStream >> data_;
    std::vector<std::string> vec;
    for (const auto& name : data_["femaleNames"]) {
        vec.push_back(name);
    }
    for (const auto& name : data_["maleNames"]) {
        vec.push_back(name);
    }
    for(uint8_t i {0}; i < 50; ++i) {
        auto ptr = director.create();
        ASSERT_TRUE(std::find(vec.cbegin(), vec.cend(), ptr->getName()) != vec.cend());
    }
}

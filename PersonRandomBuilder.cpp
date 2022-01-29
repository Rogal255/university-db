#include "PersonRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

PersonRandomBuilder::PersonRandomBuilder() {
    std::fstream fileStream("assets/data.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot find data.json");
    }
    fileStream >> data;
    fileStream.close();
    std::cout << data.dump(4) << '\n';
}

void PersonRandomBuilder::setName() noexcept { }
void PersonRandomBuilder::setSurname() noexcept { }
void PersonRandomBuilder::setAddress() noexcept { }
BuilderError PersonRandomBuilder::setGender() noexcept { return BuilderError::OK; }
BuilderError PersonRandomBuilder::setPersonalID() noexcept { return BuilderError::OK; }

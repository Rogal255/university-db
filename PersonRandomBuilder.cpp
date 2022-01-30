#include "PersonRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <random>
#include <stdexcept>

PersonRandomBuilder::PersonRandomBuilder() {
    std::fstream fileStream("assets/data.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot find data.json");
    }
    fileStream >> data;
}

void PersonRandomBuilder::setName() noexcept {
    gender_ = static_cast<Gender>(mt() % 2);
    if (gender_ == Gender::Female) {
        object->name_ = data["femaleNames"][mt() % data["femaleNames"].size()];
    } else if (gender_ == Gender::Male) {
        object->name_ = data["maleNames"][mt() % data["maleNames"].size()];
    }
}

void PersonRandomBuilder::setSurname() noexcept {
    if (gender_ == Gender::Female) {
        object->surname_ = data["femaleSurnames"][mt() % data["femaleNames"].size()];
    } else if (gender_ == Gender::Male) {
        object->surname_ = data["maleSurnames"][mt() % data["maleNames"].size()];
    }
}
void PersonRandomBuilder::setAddress() noexcept { }

BuilderError PersonRandomBuilder::setGender() noexcept {
    object->gender_ = gender_;
    return BuilderError::OK;
}
BuilderError PersonRandomBuilder::setPersonalID() noexcept { return BuilderError::OK; }

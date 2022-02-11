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

void PersonRandomBuilder::setName() {
    gender_ = static_cast<Gender>(getRandomNumber(0, 1));
    if (gender_ == Gender::Female) {
        object->name_ = data["femaleNames"][getRandomNumber(0, data["femaleNames"].size() - 1)];
    } else if (gender_ == Gender::Male) {
        object->name_ = data["maleNames"][getRandomNumber(0, data["maleNames"].size() - 1)];
    }
}

void PersonRandomBuilder::setSurname() {
    if (gender_ == Gender::Female) {
        object->surname_ = data["femaleSurnames"][getRandomNumber(0, data["femaleSurnames"].size() - 1)];
    } else if (gender_ == Gender::Male) {
        object->surname_ = data["maleSurnames"][getRandomNumber(0, data["maleSurnames"].size() - 1)];
    }
}
void PersonRandomBuilder::setAddress() {
    // Addresses don't reflect real places - they are generated randomly from possible values of streets, cities etc
    object->address_.building = std::to_string(getRandomNumber(1, 100));
    object->address_.flat = std::to_string(getRandomNumber(1, 300));
    object->address_.street = data["streets"][getRandomNumber(0, data["streets"].size() - 1)];
    object->address_.city = data["cities"][getRandomNumber(0, data["cities"].size() - 1)];
    object->address_.country = "Polska";
    std::string zipFirstPart = "0" + std::to_string(getRandomNumber(1, 99));
    std::string zipSecondPart = "00" + std::to_string(getRandomNumber(1, 999));
    object->address_.zip
        = zipFirstPart.substr(zipFirstPart.size() - 2, 2) + "-" + zipSecondPart.substr(zipSecondPart.size() - 3, 3);
}

BuilderError PersonRandomBuilder::setGender() noexcept {
    object->gender_ = gender_;
    return BuilderError::OK;
}

BuilderError PersonRandomBuilder::setPersonalID() {
    static std::size_t femaleID {0};
    static std::size_t maleID {0};
    if (gender_ == Gender::Female) {
        if (femaleID == data["femaleIDs"].size()) {
            return BuilderError::BadPersonalID;
        }
        if (checkPersonalID(data["femaleIDs"][femaleID])) {
            object->personalID_ = data["femaleIDs"][femaleID++];
            return BuilderError::OK;
        }
    } else if (gender_ == Gender::Male) {
        if (maleID == data["maleIDs"].size()) {
            return BuilderError::BadPersonalID;
        }
        if (checkPersonalID(data["maleIDs"][maleID])) {
            object->personalID_ = data["maleIDs"][maleID++];
            return BuilderError::OK;
        }
    }
    return BuilderError::BadPersonalID;
}

std::size_t PersonRandomBuilder::getRandomNumber(std::size_t from, std::size_t to) noexcept {
    std::random_device rd;
    std::mt19937 gen {rd()};
    std::uniform_int_distribution distrib(from, to);
    return distrib(gen);
}

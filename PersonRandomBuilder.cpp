#include "PersonRandomBuilder.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <random>
#include <stdexcept>
#include <type_traits>

PersonRandomBuilder::PersonRandomBuilder() {
    std::fstream fileStream("assets/data.json");
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot find data.json");
    }
    fileStream >> data;
}

void PersonRandomBuilder::setName() {
    gender_ = static_cast<Gender>(getRandomNumber<uint8_t>(0, 1));
    if (gender_ == Gender::Female) {
        object->name_ = data["femaleNames"][getRandomNumber<std::size_t>(0, data["femaleNames"].size() - 1)];
    } else if (gender_ == Gender::Male) {
        object->name_ = data["maleNames"][getRandomNumber<std::size_t>(0, data["maleNames"].size() - 1)];
    }
}

void PersonRandomBuilder::setSurname() {
    if (gender_ == Gender::Female) {
        object->surname_ = data["femaleSurnames"][getRandomNumber<std::size_t>(0, data["femaleSurnames"].size() - 1)];
    } else if (gender_ == Gender::Male) {
        object->surname_ = data["maleSurnames"][getRandomNumber<std::size_t>(0, data["maleSurnames"].size() - 1)];
    }
}
void PersonRandomBuilder::setAddress() { }

BuilderError PersonRandomBuilder::setGender() noexcept {
    object->gender_ = gender_;
    return BuilderError::OK;
}
BuilderError PersonRandomBuilder::setPersonalID() { return BuilderError::OK; }

template <typename T>
T PersonRandomBuilder::getRandomNumber(T from, T to) noexcept requires std::is_integral_v<T> {
    std::random_device rd;
    std::mt19937 gen {rd()};
    std::uniform_int_distribution<T> distrib(from, to);
    return distrib(gen);
}

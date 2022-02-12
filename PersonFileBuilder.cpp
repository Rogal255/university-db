#include "PersonFileBuilder.hpp"
#include "nlohmann/json.hpp"
#include "Helpers.hpp"
#include <string>

void PersonFileBuilder::setName() { object->name_ = data_["name"]; }
void PersonFileBuilder::setSurname() { object->surname_ = data_["surname"]; }

void PersonFileBuilder::setAddress() {
    object->address_.street = data_["address"]["street"];
    object->address_.building = data_["address"]["building"];
    object->address_.flat = data_["address"]["flat"];
    object->address_.city = data_["address"]["city"];
    object->address_.zip = data_["address"]["zip"];
    object->address_.country = data_["address"]["country"];
}

BuilderError PersonFileBuilder::setGender() {
    object->gender_ = static_cast<Gender>(data_["gender"]);
    return BuilderError::OK;
}

BuilderError PersonFileBuilder::setPersonalID() {
    std::string personalID {data_["id"]};
    if (checkPersonalID(personalID)) {
        object->personalID_ = personalID;
        return BuilderError::OK;
    }
    return BuilderError::BadPersonalID;
}

void PersonFileBuilder::setData(const nlohmann::json& data) noexcept { data_ = data; }

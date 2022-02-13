#include "PersonManualBuilder.hpp"
#include "Helpers.hpp"
#include "Person.hpp"
#include <iostream>

void PersonManualBuilder::setName() noexcept {
    std::cout << "Name = ";
    std::cin >> object->name_;
}
void PersonManualBuilder::setSurname() noexcept {
    std::cout << "Surname = ";
    std::cin >> object->surname_;
}
void PersonManualBuilder::setAddress() noexcept {
    std::cout << "Street = ";
    std::cin >> object->address_.street;
    std::cout << "Building = ";
    std::cin >> object->address_.building;
    std::cout << "Flat = ";
    std::cin >> object->address_.flat;
    std::cout << "City = ";
    std::cin >> object->address_.city;
    std::cout << "Zip code = ";
    std::cin >> object->address_.zip;
    std::cout << "Country = ";
    std::cin >> object->address_.country;
}

BuilderError PersonManualBuilder::setGender() noexcept {
    int gender;
    std::cout << "Gender[0 - female, 1 - male, 2 - not specified] = ";
    std::cin >> gender;
    if (gender >= static_cast<int>(Gender::Size)) {
        std::cout << "Bad gender provided. Gender of this person will be not specified.\n";
        return BuilderError::BadGender;
    }
    object->gender_ = static_cast<Gender>(gender);
    return BuilderError::OK;
}

BuilderError PersonManualBuilder::setPersonalID() noexcept {
    std::string personalID;
    uint8_t attempts {0};
    do {
        if (attempts > 2) {
            std::cout << "Provided ID is not valid. Personal ID of this person will be left blank.\n";
            break;
        }
        if (attempts > 0) {
            std::cout << "Provided ID is not valid. You have " << (3 - attempts) << " more attempts.\n";
        }
        attempts++;
        std::cout << "Personal ID = ";
        std::cin >> personalID;
    } while (!checkPersonalID(personalID));
    if (attempts > 2) {
        return BuilderError::BadPersonalID;
    }
    object->personalID_ = personalID;
    return BuilderError::OK;
}

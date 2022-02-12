#include "Person.hpp"
#include "Helpers.hpp"
#include <iostream>
#include <optional>
#include <stdexcept>

const std::string& Person::getName() const noexcept { return name_; };
const std::string& Person::getSurname() const noexcept { return surname_; };
const Address& Person::getAddress() const noexcept { return address_; };
Gender Person::getGender() const noexcept { return gender_; };
const std::string& Person::getPersonalID() const noexcept { return personalID_; };
std::optional<std::size_t> Person::getIndex() const noexcept { return std::nullopt; };
std::optional<std::size_t> Person::getSalary() const noexcept { return std::nullopt; };
bool Person::setIndex(std::size_t) noexcept { return false; }
bool Person::setSalary(std::size_t) noexcept { return false; };

void Person::printBasicDataToConsole() const {
    std::cout << name_ << ' ' << surname_ << '\n';
    std::cout << "Gender: ";
    switch (gender_) {
    case Gender::Male:
        std::cout << "Male";
        break;
    case Gender::Female:
        std::cout << "Female";
        break;
    case Gender::NotSpecified:
        std::cout << "Not Specified";
        break;
    default:
        throw std::out_of_range("Gender out of range");
    }
    std::cout << "\nPESEL: " << personalID_ << '\n'
              << address_.street << ' ' << address_.building << '/' << address_.flat << '\n'
              << address_.city << ' ' << address_.zip << '\n'
              << address_.country << '\n';
}
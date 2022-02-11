#include "Person.hpp"
#include <iostream>
#include <optional>
#include <string>

const std::string& Person::getName() noexcept { return name_; };
const std::string& Person::getSurname() noexcept { return surname_; };
const Address& Person::getAddress() noexcept { return address_; };
Gender Person::getGender() noexcept { return gender_; };
const std::string& Person::getPersonalID() noexcept { return personalID_; };
std::optional<std::size_t> Person::getIndex() noexcept { return std::nullopt; };
std::optional<std::size_t> Person::getSalary() noexcept { return std::nullopt; };
bool Person::setIndex(std::size_t) noexcept { return false; }
bool Person::setSalary(std::size_t) noexcept { return false; };

void Person::printBasicDataToConsole() const {
    std::cout << name_ << ' ' << surname_ << '\n'
              << "PESEL: " << personalID_ << '\n'
              << address_.street << ' ' << address_.building << '/' << address_.flat << '\n'
              << address_.city << ' ' << address_.zip << '\n'
              << address_.country << '\n';
}
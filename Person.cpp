#include "Person.hpp"
#include <optional>
#include <string>

const std::string& Person::getName() noexcept { return name_; };
const std::string& Person::getSurname() noexcept { return surname_; };
const Address& Person::getAddress() noexcept { return address_; };
Gender Person::getGender() noexcept { return gender_; };
const std::string& Person::getPersonalID() noexcept { return personalID_; };
std::optional<std::size_t> Person::getIndex() noexcept { return std::nullopt; };
std::optional<std::size_t> Person::getSalary() noexcept { return std::nullopt; };
bool Person::setIndex() noexcept { return false; }
bool Person::setSalary() noexcept { return false; };

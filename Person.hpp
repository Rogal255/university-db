#pragma once

#include "Helpers.hpp"
#include <optional>
#include <string>

class PersonManualBuilder;

class Person {
    friend PersonManualBuilder;

public:
    virtual ~Person() = default;
    const std::string& getName() noexcept;
    const std::string& getSurname() noexcept;
    const Address& getAddress() noexcept;
    Gender getGender() noexcept;
    const std::string& getPersonalID() noexcept;
    virtual std::optional<std::size_t> getIndex() noexcept;
    virtual std::optional<std::size_t> getSalary() noexcept;
    virtual bool setIndex(std::size_t) noexcept;
    virtual bool setSalary(std::size_t) noexcept;

private:
    std::string name_;
    std::string surname_;
    Address address_;
    Gender gender_;
    std::string personalID_;
};

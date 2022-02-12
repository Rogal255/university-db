#pragma once

#include "Helpers.hpp"
#include <optional>
#include <string>

class Person {
    friend class PersonManualBuilder;
    friend class PersonRandomBuilder;
    friend class PersonFileBuilder;

public:
    virtual ~Person() = default;
    [[nodiscard]] const std::string& getName() const noexcept;
    [[nodiscard]] const std::string& getSurname() const noexcept;
    [[nodiscard]] const Address& getAddress() const noexcept;
    [[nodiscard]] Gender getGender() const noexcept;
    [[nodiscard]] const std::string& getPersonalID() const noexcept;
    [[nodiscard]] virtual std::optional<std::size_t> getIndex() const noexcept;
    [[nodiscard]] virtual std::optional<std::size_t> getSalary() const noexcept;
    virtual bool setIndex(std::size_t) noexcept;
    virtual bool setSalary(std::size_t) noexcept;
    virtual void printToConsole() const = 0;

protected:
    Person() = default;
    void printBasicDataToConsole() const;

private:
    std::string name_;
    std::string surname_;
    Address address_;
    Gender gender_ {Gender::NotSpecified};
    std::string personalID_;
};

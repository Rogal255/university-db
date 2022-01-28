#pragma once
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

class Database {
public:
    [[nodiscard]] std::vector<const Person*> searchBySurname(const std::string& surname) const noexcept;
    [[nodiscard]] std::optional<const Person*> searchByPersonalID(const std::string& personalID) const noexcept;
    void sortBySurname() noexcept;
    void sortByPersonalID() noexcept;
    void sortBySalary() noexcept;
    bool changeSalary(std::size_t personalID) noexcept;
    bool deleteByIndex(std::size_t index) noexcept;

private:
    std::vector<std::unique_ptr<Person>> db_;
};

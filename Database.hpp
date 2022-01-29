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
    void addPerson(std::unique_ptr<Person> personPtr);
    [[nodiscard]] std::vector<const Person*> searchBySurname(const std::string& surname) const noexcept;
    [[nodiscard]] std::optional<Person*> searchByPersonalID(const std::string& personalID) const noexcept;
    void sortBySurname() noexcept;
    void sortByPersonalID() noexcept;
    void sortBySalary() noexcept;
    [[nodiscard]] bool changeSalary(const std::string& personalID, std::size_t newSalary) const noexcept;
    [[nodiscard]] bool deleteByIndex(std::size_t index) noexcept;

private:
    std::vector<std::unique_ptr<Person>> db_;
    static std::size_t getSalary(std::unique_ptr<Person>& person) noexcept;
};

#pragma once
#include "Person.hpp"

class Employee : public Person {
    friend class EmployeeManualBuilder;
    friend class EmployeeRandomBuilder;
    friend class EmployeeFileBuilder;

public:
    ~Employee() override = default;
    std::optional<std::size_t> getSalary() noexcept override;
    bool setSalary(std::size_t newSalary) noexcept override;
    void printToConsole() const override;

private:
    Employee() = default;
    std::size_t salary_ {0};
};

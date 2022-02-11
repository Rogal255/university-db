#include "Employee.hpp"
#include <iostream>

std::optional<std::size_t> Employee::getSalary() noexcept { return salary_; }

bool Employee::setSalary(std::size_t newSalary) noexcept {
    salary_ = newSalary;
    return true;
}

void Employee::printToConsole() const {
    std::cout << "**********\n"
              << "Employee\n";
    printBasicDataToConsole();
    std::cout << "Salary: " << salary_ << " PLN\n";
}
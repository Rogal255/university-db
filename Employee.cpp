#include "Employee.hpp"

std::optional<std::size_t> Employee::getSalary() noexcept { return salary_; }

bool Employee::setSalary(std::size_t newSalary) noexcept {
    salary_ = newSalary;
    return true;
}

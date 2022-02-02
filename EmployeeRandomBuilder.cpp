#include "EmployeeRandomBuilder.hpp"
#include "Employee.hpp"

void EmployeeRandomBuilder::init() noexcept { object = std::unique_ptr<Employee>(new Employee); }

void EmployeeRandomBuilder::setCustomData() noexcept { object->setSalary(getRandomNumber(minSalary, maxSalary)); }

#include "EmployeeManualBuilder.hpp"
#include "Employee.hpp"
#include <iostream>

void EmployeeManualBuilder::init() noexcept { object = std::unique_ptr<Employee>(new Employee); }

void EmployeeManualBuilder::setCustomData() noexcept {
    std::size_t salary {0};
    std::cout << "Salary = ";
    std::cin >> salary;
    object->setSalary(salary);
}

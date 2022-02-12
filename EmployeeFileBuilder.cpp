#include "EmployeeFileBuilder.hpp"
#include "Employee.hpp"

void EmployeeFileBuilder::init() noexcept { object = std::unique_ptr<Employee>(new Employee); };
void EmployeeFileBuilder::setCustomData() noexcept { object->setSalary(data_["salary"]); }

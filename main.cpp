#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentManualBuilder.hpp"
#include "EmployeeManualBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    StudentManualBuilder studentBuilder;
    EmployeeManualBuilder employeeBuilder;
    PersonBuilderDirector director(&studentBuilder);
    std::unique_ptr<Person> student = director.create();
    std::cout << *student->getIndex() << '\n';
    director.changeBuilder(&employeeBuilder);
    std::unique_ptr<Person> employee = director.create();
    std::cout << *employee->getSalary() << '\n';
    return 0;
}

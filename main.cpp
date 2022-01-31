#include "EmployeeManualBuilder.hpp"
#include "EmployeeRandomBuilder.hpp"
#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentRandomBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    EmployeeRandomBuilder employeeBuilder;
    PersonBuilderDirector director(&employeeBuilder);
    std::unique_ptr<Person> ptr;
    for (uint8_t i {0}; i < 100; ++i) {
        ptr = director.create();
        std::cout << ptr->getName() << ' ' << ptr->getSurname() << ' ' << *ptr->getSalary() << '\n';
    }
    return 0;
}

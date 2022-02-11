#include "Database.hpp"
#include "EmployeeManualBuilder.hpp"
#include "EmployeeRandomBuilder.hpp"
#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentRandomBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    Database db;
    EmployeeRandomBuilder employeeBuilder;
    PersonBuilderDirector director(&employeeBuilder);
    std::unique_ptr<Person> ptr;
    for (uint8_t i {0}; i < 5; ++i) {
        db.addPerson(director.create());
    }
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    for (uint8_t i {0}; i < 50; ++i) {
        db.addPerson(director.create());
    }
    db.printToConsole();
    std::string id {};
    std::cout << "PersonalID to change salary: ";
    std::cin >> id;
    std::cout << "New salary: ";
    std::size_t newSalary;
    std::cin >> newSalary;
    if (db.changeSalary(id, newSalary)) {
        db.printToConsole();
    }
    return 0;
}

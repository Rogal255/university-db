#include "EmployeeManualBuilder.hpp"
#include "EmployeeRandomBuilder.hpp"
#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentRandomBuilder.hpp"
#include "Database.hpp"
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
    //db.printToConsole();
    db.sortByPersonalID();
    db.printToConsole();
    return 0;
}

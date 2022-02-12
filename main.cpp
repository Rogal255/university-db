#include "Database.hpp"
#include "DatabaseToFile.hpp"
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
    DatabaseToFile toFile;
    toFile.saveToFile(db, "test");
    return 0;
}

#include "Database.hpp"
#include "DatabaseToFile.hpp"
#include "EmployeeManualBuilder.hpp"
#include "EmployeeRandomBuilder.hpp"
#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentManualBuilder.hpp"
#include "StudentRandomBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    // Random database generation
    Database db;
    EmployeeRandomBuilder employeeBuilder;
    PersonBuilderDirector director(&employeeBuilder);
    for (uint8_t i {0}; i < 1; ++i) {
        db.addPerson(director.create());
    }
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    for (uint8_t i {0}; i < 5; ++i) {
        db.addPerson(director.create());
    }
    DatabaseToFile toFile;

    // Saving database to file
    toFile.saveToFile(db, "database");

    // Loading database from file
    Database db2;
    toFile.loadFromFile(db2, "database");
    db2.printToConsole();
    std::cout << "\n\nLets add a student!\n\n";
    StudentManualBuilder studentManualBuilder;
    director.changeBuilder(&studentManualBuilder);
    db2.addPerson(director.create());
    db2.printToConsole();
    std::cout << "\n\nYou have new employee in your university! Go and add him to the system.\n\n";
    EmployeeManualBuilder employeeManualBuilder;
    director.changeBuilder(&employeeManualBuilder);
    db2.addPerson(director.create());
    db2.printToConsole();
    std::cout << "\n\nCheck tests to see more features.\n";
    return 0;
}

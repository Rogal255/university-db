#include "Database.hpp"
#include "DatabaseToFile.hpp"
#include "EmployeeManualBuilder.hpp"
#include "EmployeeRandomBuilder.hpp"
#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentRandomBuilder.hpp"
#include <memory>

int main() {
    // Random database generation
    Database db;
    EmployeeRandomBuilder employeeBuilder;
    PersonBuilderDirector director(&employeeBuilder);
    for (uint8_t i {0}; i < 5; ++i) {
        db.addPerson(director.create());
    }
    StudentRandomBuilder studentBuilder;
    director.changeBuilder(&studentBuilder);
    for (uint8_t i {0}; i < 50; ++i) {
        db.addPerson(director.create());
    }
    // db.printToConsole();

    DatabaseToFile toFile;

    // Saving database to file
    toFile.saveToFile(db, "database");

    // Loading database from file
    Database db2;
    toFile.loadFromFile(db2, "database");
    db2.printToConsole();
    return 0;
}

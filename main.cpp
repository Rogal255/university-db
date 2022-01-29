#include "Person.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentManualBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    StudentManualBuilder studentBuilder;
    PersonBuilderDirector director(&studentBuilder);
    std::unique_ptr<Person> ptr = director.create();
    std::cout << ptr->getPersonalID() << '\n';
    return 0;
}

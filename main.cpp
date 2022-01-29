#include "Person.hpp"
#include "StudentManualBuilder.hpp"
#include <iostream>
#include <memory>

int main() {
    StudentManualBuilder studentBuilder;
    studentBuilder.init();
    studentBuilder.setName();
    studentBuilder.setSurname();
    studentBuilder.setAddress();
    studentBuilder.setGender();
    studentBuilder.setPersonalID();
    studentBuilder.setCustomData();
    std::unique_ptr<Person> ptr = studentBuilder.getObject();
    std::cout << ptr->getName() << '\n';
    return 0;
}

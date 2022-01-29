#include "StudentManualBuilder.hpp"
#include "Student.hpp"
#include <iostream>
#include <memory>

void StudentManualBuilder::init() noexcept { object = std::unique_ptr<Student>(new Student); }

void StudentManualBuilder::setCustomData() noexcept {
    std::size_t index {0};
    std::cout << "Index = ";
    std::cin >> index;
    object->setIndex(index);
}

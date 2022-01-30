#include "StudentRandomBuilder.hpp"
#include "Student.hpp"
#include <iostream>

void StudentRandomBuilder::init() noexcept { object = std::unique_ptr<Student>(new Student); }

void StudentRandomBuilder::setCustomData() noexcept {
    std::size_t index {0};
    do {
        index = mt() % maxNumberOfIndexes;
    } while (std::find(usedIndexes.cbegin(), usedIndexes.cend(), index) != usedIndexes.cend());
    object->setIndex(index);
    usedIndexes.push_back(index);
}

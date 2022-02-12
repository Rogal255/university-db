#include "Student.hpp"
#include <iostream>

std::optional<std::size_t> Student::getIndex() const noexcept { return index_; }

bool Student::setIndex(std::size_t newIndex) noexcept {
    index_ = newIndex;
    return true;
}

void Student::printToConsole() const {
    std::cout << "**********\n"
              << "Student\n";
    printBasicDataToConsole();
    std::cout << "Index nr: " << index_ << '\n';
}
#include "Student.hpp"

std::optional<std::size_t> Student::getIndex() noexcept { return index_; }

bool Student::setIndex(std::size_t newIndex) noexcept {
    index_ = newIndex;
    return true;
}
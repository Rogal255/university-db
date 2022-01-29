#pragma once
#include "Person.hpp"

class StudentManualBuilder;

class Student : public Person {
    friend StudentManualBuilder;

public:
    ~Student() override = default;
    std::optional<std::size_t> getIndex() noexcept override;
    bool setIndex(std::size_t newIndex) noexcept override;

private:
    std::size_t index_;
};

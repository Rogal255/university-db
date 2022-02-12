#pragma once
#include "Person.hpp"

class Student : public Person {
    friend class StudentManualBuilder;
    friend class StudentRandomBuilder;
    friend class StudentFileBuilder;

public:
    ~Student() override = default;
    std::optional<std::size_t> getIndex() noexcept override;
    bool setIndex(std::size_t newIndex) noexcept override;
    void printToConsole() const override;

private:
    Student() = default;
    std::size_t index_ {0};
};

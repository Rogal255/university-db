#pragma once
#include "Person.hpp"

class Employee : public Person {
public:
    ~Employee() override = default;
    std::optional<std::size_t> getSalary() noexcept override;
    bool setSalary(std::size_t newSalary) noexcept override;

private:
    std::size_t salary_;
};

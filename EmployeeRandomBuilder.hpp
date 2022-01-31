#pragma once
#include "PersonRandomBuilder.hpp"

class EmployeeRandomBuilder : public PersonRandomBuilder {
public:
    ~EmployeeRandomBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;

private:
    std::size_t minSalary {3000};
    std::size_t maxSalary {20000};
};

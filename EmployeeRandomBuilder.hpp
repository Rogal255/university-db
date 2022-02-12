#pragma once
#include "PersonRandomBuilder.hpp"

class EmployeeRandomBuilder : public PersonRandomBuilder {
public:
    ~EmployeeRandomBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;

private:
    int minSalary {3000};
    int maxSalary {20000};
};

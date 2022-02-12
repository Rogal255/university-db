#pragma once
#include "PersonFileBuilder.hpp"

class EmployeeFileBuilder : public PersonFileBuilder {
public:
    ~EmployeeFileBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;
};

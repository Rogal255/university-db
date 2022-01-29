#pragma once
#include "PersonManualBuilder.hpp"

class EmployeeManualBuilder : public PersonManualBuilder {
public:
    ~EmployeeManualBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;
};

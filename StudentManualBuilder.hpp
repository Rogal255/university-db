#pragma once
#include "PersonManualBuilder.hpp"

class StudentManualBuilder : public PersonManualBuilder {
public:
    ~StudentManualBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;
};

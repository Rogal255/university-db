#pragma once
#include "PersonFileBuilder.hpp"

class StudentFileBuilder : public PersonFileBuilder {
public:
    ~StudentFileBuilder() override = default;
    void init() noexcept final;
    void setCustomData() noexcept final;
};

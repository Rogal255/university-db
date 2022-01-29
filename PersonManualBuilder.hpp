#pragma once
#include "PersonBuilder.hpp"

class PersonManualBuilder : public PersonBuilder {
public:
    ~PersonManualBuilder() override = default;
    void init() noexcept override = 0;
    void setName() noexcept final;
    void setSurname() noexcept final;
    void setAddress() noexcept final;
    BuilderError setGender() noexcept final;
    BuilderError setPersonalID() noexcept final;
    void setCustomData() noexcept override = 0;
};

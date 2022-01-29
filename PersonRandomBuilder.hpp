#pragma once
#include "PersonBuilder.hpp"
#include "nlohmann/json.hpp"

class PersonRandomBuilder : public PersonBuilder {
public:
    PersonRandomBuilder();
    ~PersonRandomBuilder() override = default;
    void init() noexcept override { };
    void setName() noexcept final;
    void setSurname() noexcept final;
    void setAddress() noexcept final;
    BuilderError setGender() noexcept final;
    BuilderError setPersonalID() noexcept final;
    void setCustomData() noexcept override {};

private:
    nlohmann::json data;
};

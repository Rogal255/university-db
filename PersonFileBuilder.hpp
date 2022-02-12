#pragma once
#include "Helpers.hpp"
#include "nlohmann/json.hpp"
#include "PersonBuilder.hpp"

class PersonFileBuilder : public PersonBuilder {
public:
    virtual ~PersonFileBuilder() override = default;
    void init() noexcept override = 0;
    void setName() final;
    void setSurname() final;
    void setAddress() final;
    BuilderError setGender() final;
    BuilderError setPersonalID() final;
    void setCustomData() override = 0;
    void setData(const nlohmann::json& data) noexcept;

protected:
    nlohmann::json data_;
};

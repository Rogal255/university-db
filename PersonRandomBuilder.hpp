#pragma once
#include "nlohmann/json.hpp"
#include "PersonBuilder.hpp"
#include <random>

class PersonRandomBuilder : public PersonBuilder {
public:
    PersonRandomBuilder();
    ~PersonRandomBuilder() override = default;
    void init() noexcept override = 0;
    void setName() noexcept final;
    void setSurname() noexcept final;
    void setAddress() noexcept final;
    BuilderError setGender() noexcept final;
    BuilderError setPersonalID() noexcept final;
    void setCustomData() noexcept override = 0;

protected:
    std::random_device rd {};
    std::mt19937 mt {rd()};

private:
    nlohmann::json data;
    Gender gender_ {Gender::NotSpecified};
};

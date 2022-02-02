#pragma once
#include "nlohmann/json.hpp"
#include "PersonBuilder.hpp"
#include <random>
#include <type_traits>

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
    template <typename T>
    T getRandomNumber(T from, T to) requires std::is_integral_v<T>;

private : nlohmann::json data;
    Gender gender_ {Gender::NotSpecified};
};

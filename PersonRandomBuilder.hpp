#pragma once
#include "nlohmann/json.hpp"
#include "PersonBuilder.hpp"

class PersonRandomBuilder : public PersonBuilder {
public:
    PersonRandomBuilder();
    ~PersonRandomBuilder() override = default;
    void init() noexcept override = 0;
    void setName() final;
    void setSurname() final;
    void setAddress() final;
    BuilderError setGender() noexcept final;
    BuilderError setPersonalID() final;
    void setCustomData() override = 0;

protected:
    static std::size_t getRandomNumber(int from, int to) noexcept;

private:
    nlohmann::json data;
    Gender gender_ {Gender::NotSpecified};
    static std::size_t femaleID;
    static std::size_t maleID;
};

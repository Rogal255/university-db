#pragma once
#include <memory>
#include <string>
#include "Helpers.hpp"
#include "Person.hpp"

class PersonBuilder {
public:
    virtual ~PersonBuilder() = default;
    virtual void init() noexcept = 0;
    virtual void setName() noexcept = 0;
    virtual void setSurname() noexcept = 0;
    virtual void setAddress() noexcept = 0;
    virtual BuilderError setGender() noexcept = 0;
    virtual BuilderError setPersonalID() noexcept = 0;
    virtual void setCustomData() noexcept = 0;
    std::unique_ptr<Person> getObject();

protected:
    bool checkPersonalID(const std::string& personalID);
    std::unique_ptr<Person> object {nullptr};
};

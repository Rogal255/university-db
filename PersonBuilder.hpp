#pragma once
#include "Helpers.hpp"
#include "Person.hpp"
#include <memory>
#include <string>

class PersonBuilder {
public:
    virtual ~PersonBuilder() = default;
    virtual void init() noexcept = 0;
    virtual void setName() = 0;
    virtual void setSurname() = 0;
    virtual void setAddress() = 0;
    virtual BuilderError setGender() = 0;
    virtual BuilderError setPersonalID() = 0;
    virtual void setCustomData() = 0;
    std::unique_ptr<Person> getObject();

protected:
    static bool checkPersonalID(const std::string& personalID);
    std::unique_ptr<Person> object {nullptr};
};

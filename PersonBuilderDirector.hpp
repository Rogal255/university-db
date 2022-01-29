#pragma once
#include "Person.hpp"
#include "PersonBuilder.hpp"
#include <memory>

class PersonBuilderDirector {
public:
    PersonBuilderDirector() = default;
    explicit PersonBuilderDirector(PersonBuilder* t_Builder);
    void changeBuilder(PersonBuilder* t_Builder);
    std::unique_ptr<Person> create();

private:
    PersonBuilder* builder {nullptr};
};

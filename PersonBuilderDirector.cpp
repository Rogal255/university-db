#include "PersonBuilderDirector.hpp"
#include "Helpers.hpp"
#include <iostream>

PersonBuilderDirector::PersonBuilderDirector(PersonBuilder* t_Builder) : builder {t_Builder} { }

void PersonBuilderDirector::changeBuilder(PersonBuilder* t_Builder) { builder = t_Builder; }

std::unique_ptr<Person> PersonBuilderDirector::create() {
    builder->init();
    builder->setName();
    builder->setSurname();
    if (builder->setGender() == BuilderError::BadGender) {
        std::cout << "!!!Error while setting gender. Value hasn't been set.\n";
    }
    if (builder->setPersonalID() == BuilderError::BadPersonalID) {
        std::cout << "!!!Error while setting Personal ID. Value hasn't been set.\n";
    }
    builder->setAddress();
    builder->setCustomData();
    return builder->getObject();
}

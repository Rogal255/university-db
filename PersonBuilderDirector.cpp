#include "PersonBuilderDirector.hpp"

PersonBuilderDirector::PersonBuilderDirector(PersonBuilder* t_Builder) : builder {t_Builder} { }

void PersonBuilderDirector::changeBuilder(PersonBuilder* t_Builder) { builder = t_Builder; }

std::unique_ptr<Person> PersonBuilderDirector::create() {
    builder->init();
    builder->setName();
    builder->setSurname();
    builder->setGender();
    builder->setPersonalID();
    builder->setAddress();
    builder->setCustomData();
    return builder->getObject();
}

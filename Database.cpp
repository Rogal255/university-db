#include "Database.hpp"
#include "Person.hpp"
#include <algorithm>
#include <memory>
#include <optional>

void Database::addPerson(std::unique_ptr<Person> personPtr) { db_.push_back(std::move(personPtr)); }

std::vector<const Person*> Database::searchBySurname(const std::string& surname) const noexcept {
    std::vector<const Person*> vec;
    for (auto it = db_.cbegin();;) {
        it = std::find_if(it, db_.cend(), [&](auto& person) { return person->getSurname() == surname; });
        if (it == db_.cend()) {
            return vec;
        }
        vec.push_back(it->get());
        ++it;
    }
}

std::optional<Person*> Database::searchByPersonalID(const std::string& personalID) const noexcept {
    auto it
        = std::find_if(db_.cbegin(), db_.cend(), [&](auto& person) { return person->getPersonalID() == personalID; });
    if (it == db_.cend()) {
        return std::nullopt;
    }
    return it->get();
}

void Database::sortBySurname() noexcept {
    std::sort(db_.begin(), db_.end(), [](auto& person1, auto& person2) {
        return person1->getSurname() < person2->getSurname();
    });
}

void Database::sortByPersonalID() noexcept {
    std::sort(db_.begin(), db_.end(), [](auto& person1, auto& person2) {
        return person1->getPersonalID() < person2->getPersonalID();
    });
}

void Database::sortBySalary() noexcept {
    std::sort(db_.begin(), db_.end(), [](auto& person1, auto& person2) {
        return Database::getSalary(person1) > Database::getSalary(person2);
    });
}

bool Database::changeSalary(const std::string& personalID, std::size_t newSalary) const noexcept {
    if (auto personOpt = searchByPersonalID(personalID)) {
        if ((*personOpt)->setSalary(newSalary)) {
            return true;
        }
    }
    return false;
}

bool Database::deleteByIndex(std::size_t index) noexcept {
    auto it = std::find_if(db_.cbegin(), db_.cend(), [&](auto& person) {
        if (auto opt = person->getIndex()) {
            return *opt == index;
        }
        return false;
    });
    if (it != db_.end()) {
        db_.erase(it);
        return true;
    }
    return false;
}

void Database::printToConsole() {
    for (const auto& person : db_) {
        person->printToConsole();
    }
}

std::size_t Database::getSalary(std::unique_ptr<Person>& person) noexcept {
    if (auto opt = person->getSalary()) {
        return *opt;
    }
    return 0;
}
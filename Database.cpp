#include "Database.hpp"
#include "Person.hpp"
#include <algorithm>
#include <memory>
#include <optional>

std::vector<const Person*> Database::searchBySurname(const std::string& surname) const noexcept {
    std::vector<const Person*> vec;
    for (auto it = db_.cbegin();;) {
        it = std::find_if(it, db_.cend(), [&](auto& person) { return person->getSurname() == surname; });
        if (it == db_.cend()) {
            return vec;
        }
        vec.push_back(it->get());
    }
}

std::optional<const Person*> Database::searchByPersonalID(const std::string& personalID) const noexcept {
    auto it
        = std::find_if(db_.cbegin(), db_.cend(), [&](auto& person) { return person->getPersonalID() == personalID; });
    if (it == db_.cend()) {
        return std::nullopt;
    }
    return it->get();
}
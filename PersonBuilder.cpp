#include "PersonBuilder.hpp"
#include <algorithm>
#include <array>

bool PersonBuilder::checkPersonalID(const std::string& personalID) {
    if (personalID.size() != 11) {
        return false;
    }
    if (!std::all_of(personalID.cbegin(), personalID.cend(), ::isdigit)) {
        return false;
    }
    uint16_t sumWeights {0};
    std::array<uint8_t, 11> personalIDArr {0};
    constexpr std::array<uint8_t, 11> personalIDWeights {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    for (uint8_t i = 0; i < personalID.size(); ++i) {
        personalIDArr[i] = static_cast<uint8_t>(personalID[i] - '0');
    }
    for (uint8_t i = 0; i < personalIDWeights.size(); ++i) {
        sumWeights += personalIDArr[i] * personalIDWeights[i];
    }
    if (personalIDArr[10] == 10 - sumWeights % 10) {
        return true;
    }
    if (personalIDArr[10] == 0 && sumWeights % 10 == 0) {
        return true;
    }
    return false;
}

std::unique_ptr<Person> PersonBuilder::getObject() { return std::move(object); }

#pragma once
#include <string>

enum class Gender : uint8_t { Female, Male, NotSpecified };

struct Address {
    std::string street {};
    std::string building {};
    std::string flat {};
    std::string city {};
    std::string zip {};
    std::string country {};
};

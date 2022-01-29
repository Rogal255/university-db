#pragma once
#include <string>

enum class Gender : uint8_t { Female, Male, NotSpecified, Size };

enum class BuilderError : uint8_t { OK, BadGender, BadPersonalID, Size };

struct Address {
    std::string street {};
    std::string building {};
    std::string flat {};
    std::string city {};
    std::string zip {};
    std::string country {};
};

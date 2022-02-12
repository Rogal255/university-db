#pragma once
#include "Database.hpp"
#include "nlohmann/json.hpp"
#include <string>

class DatabaseToFile {
public:
    void saveToFile(const Database& db, std::string&& fileName);

private:
    void toJson(const Database& db);
    nlohmann::json data_;
};

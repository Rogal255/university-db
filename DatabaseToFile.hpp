#pragma once
#include "Database.hpp"
#include "nlohmann/json.hpp"
#include <string>

class DatabaseToFile {
public:
    void saveToFile(const Database& db, std::string&& fileName);
    void loadFromFile(Database& db, std::string&& fileName);

private:
    void toJson(const Database& db);
    void fromJson(Database& db);
    nlohmann::json data_;
};

#include "DatabaseToFile.hpp"
#include "Database.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>

void DatabaseToFile::saveToFile(const Database& db, std::string&& fileName) {
    toJson(db);
    fileName += ".json";
    std::ofstream fileStream(fileName);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    fileStream << std::setw(4) << data_;
}

void DatabaseToFile::toJson(const Database& db) {
    data_.clear();
    for (std::size_t i {0}; i < db.db_.size(); ++i) {
        data_[i]["name"] = db.db_[i]->getName();
        data_[i]["surname"] = db.db_[i]->getSurname();
        data_[i]["gender"] = static_cast<uint8_t>(db.db_[i]->getGender());
        data_[i]["id"] = db.db_[i]->getPersonalID();
        data_[i]["address"]["street"] = db.db_[i]->getAddress().street;
        data_[i]["address"]["building"] = db.db_[i]->getAddress().building;
        data_[i]["address"]["flat"] = db.db_[i]->getAddress().flat;
        data_[i]["address"]["city"] = db.db_[i]->getAddress().city;
        data_[i]["address"]["zip"] = db.db_[i]->getAddress().zip;
        data_[i]["address"]["country"] = db.db_[i]->getAddress().country;
        if (auto index = db.db_[i]->getIndex()) {
            data_[i]["index"] = *index;
        }
        if (auto salary = db.db_[i]->getSalary()) {
            data_[i]["salary"] = *salary;
        }
    }
}

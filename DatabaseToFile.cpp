#include "DatabaseToFile.hpp"
#include "Database.hpp"
#include "EmployeeFileBuilder.hpp"
#include "nlohmann/json.hpp"
#include "PersonBuilderDirector.hpp"
#include "StudentFileBuilder.hpp"
#include <fstream>
#include <stdexcept>
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

void DatabaseToFile::loadFromFile(Database& db, std::string&& fileName) {
    fileName += ".json";
    std::ifstream fileStream(fileName);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Cannot save to file");
    }
    data_.clear();
    db.db_.clear();
    fileStream >> data_;
    fromJson(db);
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

void DatabaseToFile::fromJson(Database& db) {
    PersonBuilderDirector director;
    StudentFileBuilder studentBuilder;
    EmployeeFileBuilder employeeBuilder;
    for (std::size_t i {0}; i < data_.size(); ++i) {
        if (data_[i].contains("index")) {
            studentBuilder.setData(data_[i]);
            director.changeBuilder(&studentBuilder);
            db.addPerson(director.create());
            continue;
        }
        if (data_[i].contains("salary")) {
            employeeBuilder.setData(data_[i]);
            director.changeBuilder(&employeeBuilder);
            db.addPerson(director.create());
            continue;
        }
        throw std::logic_error("Error reading from file");
    }
}

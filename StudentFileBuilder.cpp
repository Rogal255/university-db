#include "StudentFileBuilder.hpp"
#include "nlohmann/json.hpp"
#include "Student.hpp"
#include <memory>

void StudentFileBuilder::init() noexcept { object = std::unique_ptr<Student>(new Student); }
void StudentFileBuilder::setCustomData() noexcept { object->setIndex(data_["index"]); }

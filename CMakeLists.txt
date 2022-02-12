cmake_minimum_required(VERSION 3.21)
project(university_db)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        GIT_TAG v3.10.5)
FetchContent_MakeAvailable(json)

set(SRC_LIST
        Person.cpp
        Student.cpp
        Employee.cpp
        Database.cpp
        PersonBuilder.cpp
        PersonManualBuilder.cpp
        PersonRandomBuilder.cpp
        PersonFileBuilder.cpp
        StudentManualBuilder.cpp
        StudentRandomBuilder.cpp
        StudentFileBuilder.cpp
        EmployeeManualBuilder.cpp
        EmployeeRandomBuilder.cpp
        EmployeeFileBuilder.cpp
        PersonBuilderDirector.cpp
        DatabaseToFile.cpp)

add_library(Database STATIC ${SRC_LIST})
target_link_libraries(Database PUBLIC nlohmann_json::nlohmann_json)

add_executable(university_db main.cpp)

target_link_libraries(university_db PUBLIC Database)
file(COPY ./assets/data.json DESTINATION ./)
file(COPY ./assets DESTINATION ./Tests)

add_subdirectory(./Tests)

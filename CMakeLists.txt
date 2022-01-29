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

add_executable(university_db
        main.cpp
        Person.cpp
        Student.cpp
        Employee.cpp
        Database.cpp
        PersonBuilder.cpp
        PersonManualBuilder.cpp
        PersonRandomBuilder.cpp
        StudentManualBuilder.cpp
        EmployeeManualBuilder.cpp
        PersonBuilderDirector.cpp)

target_link_libraries(university_db PRIVATE nlohmann_json::nlohmann_json)
file(COPY ./assets DESTINATION ./)

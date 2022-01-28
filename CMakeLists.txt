cmake_minimum_required(VERSION 3.21)
project(university_db)

set(CMAKE_CXX_STANDARD 20)

add_executable(university_db main.cpp Person.cpp Student.cpp)

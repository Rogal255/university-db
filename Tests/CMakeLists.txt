FetchContent_Declare(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest.git"
        GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(RandomBuilderTest RandomBuilderTest.cpp)
target_link_libraries(RandomBuilderTest PUBLIC Database PUBLIC nlohmann_json::nlohmann_json PUBLIC gtest_main)
add_executable(DatabaseTest DatabaseTest.cpp)
target_link_libraries(DatabaseTest PUBLIC Database PUBLIC nlohmann_json::nlohmann_json PUBLIC gtest_main)

include(GoogleTest)
gtest_discover_tests(RandomBuilderTest)
gtest_discover_tests(DatabaseTest)

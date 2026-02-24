cmake_minimum_required(VERSION 4.0)
project(Vector3)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

set(VECTOR3_FILES
    src/Vector3.h
    src/Vector3.cpp
)
set(TEST_FILES
    tests/UnitTests.cpp
    tests/IntegrationTests.cpp
)

add_library(Vector3Lib STATIC ${CALCULATOR_FILES})
target_include_directories(Vector3Lib PUBLIC src)
add_executable(run_tests ${TEST_FILES})

target_link_libraries(run_tests Vector3Lib gtest_main)
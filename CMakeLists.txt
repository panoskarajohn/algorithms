cmake_minimum_required(VERSION 3.14)
project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

# --- GoogleTest setup first ---
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

# --- Library ---
file(GLOB SRC_FILES src/*.cpp)
add_library(src_algos ${SRC_FILES})
target_include_directories(src_algos PUBLIC include)

# --- Tests ---
file(GLOB TEST_SOURCES tests/test_*.cpp)
add_executable(algorithms ${TEST_SOURCES})
target_link_libraries(algorithms PRIVATE src_algos GTest::gtest_main)

# --- Discover tests ---
include(GoogleTest)
gtest_discover_tests(algorithms)


# --- GoogleTest integration ---
include(GoogleTest)
gtest_discover_tests(algorithms)

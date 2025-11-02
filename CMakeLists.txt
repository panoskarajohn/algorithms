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

# --- Output directories ---
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# --- Generate compile_commands.json ---
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Symlink compile_commands.json to root
if(NOT CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink
                ${CMAKE_BINARY_DIR}/compile_commands.json
                ${CMAKE_SOURCE_DIR}/compile_commands.json
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()

# --- Library ---
file(GLOB SRC_FILES src/*.cpp ds/*.cpp)
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

# --- Optional: export compile commands for editor integration ---
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

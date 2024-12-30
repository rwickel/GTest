# CMAKELists.txt


cmake_minimum_required(VERSION 3.14) # Ensure you have at least this version of CMake
project(GoogleTestExample VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0109 NEW)

# Enable testing
include(CTest)
enable_testing()

# Download and configure GoogleTest using FetchContent
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE  # This ensures the timestamp is updated during extraction
)

# Fetch GoogleTest content
FetchContent_MakeAvailable(googletest)

# Define the test executable
add_executable(sample_test
    test/sample_test.cpp
    src/sample.cpp
)

# Link GoogleTest libraries
target_link_libraries(sample_test gtest gtest_main)

# Add the test target
add_test(NAME SampleTest COMMAND sample_test)

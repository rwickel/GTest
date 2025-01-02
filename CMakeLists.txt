cmake_minimum_required(VERSION 3.14)
project(SampleProject)

cmake_policy(SET CMP0135 NEW)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)

# Include the header files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Add the main library
add_library(sample_lib src/sample.cpp)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE  
)
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(sample_test test/sample_test.cpp)

# Link the test executable to GoogleTest and the main library
target_link_libraries(sample_test PRIVATE sample_lib gtest_main)

# Enable testing
enable_testing()
add_test(NAME sample_test COMMAND sample_test)
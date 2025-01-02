# GoogleTest Example

This repository provides a step-by-step guide to setting up and using **GoogleTest**, a popular C++ testing framework, with **CMake**. It includes a simple example project to demonstrate how to integrate GoogleTest, write unit tests, and execute them using CMake's testing tools.

## Table of Contents
- [Project Overview](#project-overview)
- [Requirements](#requirements)
- [Setup Instructions](#setup-instructions)
  - [Cloning the Repository](#cloning-the-repository)
  - [Building and Running Tests](#building-and-running-tests)
- [Sample Test Cases](#sample-test-cases)
- [Adding New Test Cases](#adding-new-test-cases)
- [Batch Scripts](#batch-scripts)
- [CMake Options](#cmake-options)
- [License](#license)

## Project Overview

This project serves as a practical example of integrating **GoogleTest** into a C++ project using **CMake**. It includes a simple test case to verify the setup and demonstrates how to write, build, and run unit tests.

### Key Features:
- **GoogleTest Integration**: GoogleTest is automatically downloaded and integrated via CMake's `FetchContent`.
- **Example Test Case**: A sample test (`sample_test.cpp`) is provided to demonstrate basic testing functionality.
- **CMake Configuration**: The project is configured to compile and run tests using CMake's built-in testing tools.
- **Batch Scripts**: Convenient scripts are included to automate the build and test processes.
- **Test Output**: Test results are saved in a `test_results.xml` file in JUnit XML format for easy integration with CI/CD pipelines.

### What You'll Learn:
- How to set up GoogleTest using CMake's `FetchContent`.
- How to write and organize unit tests in C++.
- How to configure and run tests using CMake and `ctest`.
- How to generate test results in JUnit XML format.

## Requirements

To use this project, ensure you have the following installed:
- **CMake** (Version 3.14 or later)
- **C++ Compiler** (GCC, Clang, or MSVC)
- **Git** (for cloning the repository)

## Setup Instructions

### Cloning the Repository

To get started, clone the repository using the following command:

```bash
git clone https://github.com/yourusername/google-test-example.git
cd google-test-example
```

### Building and Running Tests

To simplify the process of building and running tests, a script named `build_and_test.sh` is provided. This script automates the entire workflow:

1. **Make the Script Executable:**

```bash
chmod +x build_and_test.sh
```

2. **Run the Script:**

```bash
./build_and_test.sh
```

![image](https://github.com/user-attachments/assets/4466c8d4-8f08-4fbe-b274-611b4f001571)


#### What the Script Does:
- **Cleans the Build Directory**: Removes any existing `build` directory to ensure a clean build.
- **Creates the Build Directory**: Initializes a new `build` directory.
- **Configures the Project**: Runs `cmake` to configure the project and download GoogleTest.
- **Builds the Project**: Compiles the project using `cmake --build .`.
- **Runs the Tests**: Executes all tests using `ctest --output-on-failure --output-junit test_results.xml`.

This script ensures that the project is built and tested in a single step, making it easy to verify changes. The test results are saved in a `test_results.xml` file in the `build` directory, formatted in JUnit XML format for compatibility with CI/CD tools.

## Sample Test Cases

The repository includes a sample test file (`sample_test.cpp`) to demonstrate how to write and run tests using GoogleTest. Here’s an explanation of the test cases:

### Test Case 1: Handles Positive Input
```cpp
TEST(AddTest, HandlesPositiveInput) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(10, 15), 25);
}
```
This test verifies that the `add` function correctly handles positive integers. It checks:
- `add(2, 3)` returns `5`.
- `add(10, 15)` returns `25`.

### Test Case 2: Handles Negative Input
```cpp
TEST(AddTest, HandlesNegativeInput) {
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(-5, -7), -12);
}
```
This test ensures the `add` function works with negative integers. It checks:
- `add(-1, 1)` returns `0`.
- `add(-5, -7)` returns `-12`.

### Test Case 3: Handles Zero Input
```cpp
TEST(AddTest, HandlesZeroInput) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(5, 0), 5);
}
```
This test validates the `add` function’s behavior with zero. It checks:
- `add(0, 0)` returns `0`.
- `add(0, 5)` returns `5`.
- `add(5, 0)` returns `5`.

### Expected Output
When you run the tests, you should see output similar to this:

```
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from AddTest
[ RUN      ] AddTest.HandlesPositiveInput
[       OK ] AddTest.HandlesPositiveInput (0 ms)
[ RUN      ] AddTest.HandlesNegativeInput
[       OK ] AddTest.HandlesNegativeInput (0 ms)
[ RUN      ] AddTest.HandlesZeroInput
[       OK ] AddTest.HandlesZeroInput (0 ms)
[----------] 3 tests from AddTest (0 ms total)

[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
```

Additionally, the test results are saved in `test_results.xml` in the `build` directory. This file is formatted in JUnit XML format, making it easy to integrate with CI/CD pipelines or other tools that support this format.

## Adding New Test Cases

To add a new test case, follow these steps:

1. **Create a New Test File:**
   Add a new `.cpp` file in the `test/` directory (e.g., `new_test.cpp`).

2. **Write the Test Case:**
   Use GoogleTest macros to define your test. Here’s an example:

```cpp
#include <gtest/gtest.h>

TEST(NewTest, Example) {
    EXPECT_EQ(1 + 1, 2);
}
```

3. **Update `CMakeLists.txt`:**
   Add the new test file to the `add_executable` command:

```cmake
add_executable(sample_test
    test/sample_test.cpp
    test/new_test.cpp  # Add the new test file here
    src/sample.cpp
)
```

4. **Rebuild and Rerun Tests:**
   Use the `build_and_test.sh` script to rebuild the project and run the tests:

```bash
./build_and_test.sh
```

This will ensure that your new test case is included and executed. The results will be appended to the `test_results.xml` file.

## Batch Scripts

### `build_and_test.sh`
This script automates the entire build and test process:

```bash
#!/bin/bash
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
ctest --output-on-failure --output-junit test_results.xml
```

### Usage
1. Make the script executable:

```bash
chmod +x build_and_test.sh
```

2. Run the script:

```bash
./build_and_test.sh
```

This will build the project, run the tests, and save the results in `test_results.xml`.

## CMake Options

This project uses CMake for build management. Here are some useful CMake options:

- **`CMAKE_BUILD_TYPE`**: Specify the build type (e.g., `Release`, `Debug`).
  
  Example:

  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  ```

- **`-G`**: Specify a generator for your IDE (e.g., Visual Studio, Xcode).
  
  Example for Visual Studio:

  ```bash
  cmake -G "Visual Studio 16 2019" ..
  ```

## License

This project is licensed under the **MIT License**. For more details, see the [LICENSE](LICENSE) file.

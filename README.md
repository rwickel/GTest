# GoogleTest Example

This repository demonstrates how to set up and use GoogleTest (a C++ testing framework) with CMake. It includes an example of how to integrate GoogleTest into a CMake project, create unit tests, and run those tests.

## Table of Contents
- [Project Overview](#project-overview)
- [Requirements](#requirements)
- [Setup Instructions](#setup-instructions)
  - [Cloning the Repository](#cloning-the-repository)
  - [Building the Project](#building-the-project)
  - [Running Tests](#running-tests)
- [Adding New Tests](#adding-new-tests)
- [Batch Scripts](#batch-scripts)
- [CMake Options](#cmake-options)
- [License](#license)

## Project Overview

This project demonstrates the use of GoogleTest in C++ projects. It uses CMake for build automation and includes a simple test case to verify the integration.

### The repository includes:
- **GoogleTest** as a submodule via CMake’s FetchContent.
- A simple example test, `sample_test.cpp`.
- Basic CMake configuration for compiling and running tests.
- Batch scripts for building and running tests.

The project shows how to:
- Set up GoogleTest using FetchContent.
- Write simple test cases.
- Configure and run tests using CMake's built-in testing functionality.

## Requirements

- **CMake** (Version 3.14 or later)
- **C++ Compiler** (GCC, Clang, or MSVC)
- **Python** (for GoogleTest dependency management)
- **Git** (for cloning the repository)

## Setup Instructions

### Cloning the Repository

To clone the repository, use the following command:

```bash
git clone https://github.com/yourusername/google-test-example.git
cd google-test-example
```

### Building the Project

1. **Create the build directory:**

```bash
mkdir build
cd build
```

2. **Configure the project with CMake:**

```bash
cmake ..
```

This will download GoogleTest (via FetchContent), configure the project, and prepare the necessary build files.

3. **Build the project:**

```bash
cmake --build .
```

This command will compile the test and create an executable.

### Running Tests

After building the project, you can run the tests with:

```bash
ctest --output-junit Testing/test_results.xml
```

This will run all the tests and output the results in the `test_results.xml` file, formatted in JUnit XML format.

## Adding New Tests

To add a new test case:

1. Create a new `.cpp` file inside the `test/` directory (for example, `new_test.cpp`).
2. Write your test case in the new file. Here's a basic example:

```cpp
#include <gtest/gtest.h>

// A simple test
TEST(SampleTest, Addition) {
    EXPECT_EQ(1 + 1, 2);
}
```

3. Update `CMakeLists.txt` to include the new test file. Modify the `add_executable` line like so:

```cmake
add_executable(sample_test
    test/sample_test.cpp
    test/new_test.cpp  # Add the new test file here
    src/sample.cpp
)
```

4. Rebuild the project and rerun the tests using the instructions above.

## Batch Scripts

### `build_project.sh`
This script automates the build process:

```bash
#!/bin/bash
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

### `run_tests.sh`
This script automates the testing process:

```bash
#!/bin/bash
cd build
ctest --output-junit Testing/test_results.xml
```

### Usage
1. Make the scripts executable:

```bash
chmod +x build_project.sh run_tests.sh
```

2. Run the scripts as needed:

- To build the project:

```bash
./build_project.sh
```

- To run the tests:

```bash
./run_tests.sh
```

## CMake Options

This project uses CMake for build management. Here are some useful CMake options:

- **`CMAKE_BUILD_TYPE`**: Set this option to specify the build type (e.g., `Release`, `Debug`).
  
  Example:

  ```bash
  cmake -DCMAKE_BUILD_TYPE=Release ..
  ```

- **`-G`**: You can specify a generator if you're using a specific IDE (e.g., Visual Studio, Xcode).
  
  Example for Visual Studio:

  ```bash
  cmake -G "Visual Studio 16 2019" ..
  ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


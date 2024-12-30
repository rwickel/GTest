#!/bin/bash
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
ctest -T test --output-junit Testing/test_results.xml
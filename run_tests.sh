#!/bin/bash
cd build
ctest -T test --output-junit Testing/test_results.xml

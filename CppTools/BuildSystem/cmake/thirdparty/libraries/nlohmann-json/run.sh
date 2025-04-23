#!/usr/bin/env bash

# Use CMake
# cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# cmake --build build
# ./build/example

# Use CMake + CPM.cmake
mkdir -p cmake
wget -O cmake/CPM.cmake https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake
cmake -S . -B build
cmake --build build
./build/example

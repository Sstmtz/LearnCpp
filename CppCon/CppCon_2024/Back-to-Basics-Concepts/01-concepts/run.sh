#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main3
./build/main7
./build/main9
./build/main10
# ./build/main17
# ./build/main18
./build/main19
./build/main21

# clang++ -std=c++20 main17.cpp -o output/main17
# ./output/main17

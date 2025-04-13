#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
# ./build/main
./build/main3

# clang++ -std=c++20 main.cpp -o output/main
# ./output/main

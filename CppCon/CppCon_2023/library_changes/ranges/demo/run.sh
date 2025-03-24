#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
# # ./build/main
# # ./build/main2
./build/main3

# clang++ -std=c++23 main3.cpp -o output/main3
# ./output/main3

#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main

# clang++ -std=c++20 main.cpp -o output/main
# ./output/main

g++ -std=c++20 main.cpp -o output/main
./output/main

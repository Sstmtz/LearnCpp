#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main
# ./build/main2
./build/main3
./build/main4
./build/main5
./build/main8
./build/main9

# clang++ -std=c++20 main.cpp -o output/main
# ./output/main

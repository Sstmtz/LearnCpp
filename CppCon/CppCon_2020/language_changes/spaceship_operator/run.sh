#!/usr/bin/env bash

mkdir -p output

CXX=clang++ cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main
./build/main2

# clang++ -std=c++20 main.cpp -o output/main
# ./output/main
# clang++ -std=c++20 main2.cpp -o output/main
# ./output/main2

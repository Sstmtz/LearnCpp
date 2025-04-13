#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
# ./build/01
# ./build/02
# ./build/03
# ./build/04
# ./build/05

clang++ -std=c++20 06-module1.cpp 07-module2.cpp -o output/module
./output/module

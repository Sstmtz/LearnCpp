#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main
./build/main2
./build/main3

# clang++ -std=c++17 main.cpp -o output/main
# ./output/main
# clang++ -std=c++17 main2.cpp -o output/main2
# ./output/main2
# clang++ -std=c++17 main3.cpp -o output/main3
# ./output/main3

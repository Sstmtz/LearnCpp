#!/usr/bin/env bash

mkdir -p output

clang++ -std=c++20 cppcon.cppm --precompile -o cppcon.pcm
clang++ -std=c++20 main.cpp -fmodule-file=cppcon=cppcon.pcm cppcon.pcm -o output/main
./output/main

CXX=clang++ cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
./build/main

# rm cppcon.pcm

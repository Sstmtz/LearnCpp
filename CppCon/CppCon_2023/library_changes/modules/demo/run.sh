#!/usr/bin/env bash

mkdir -p output

cmake -S . -B build -G Ninja -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_CXX_FLAGS=-stdlib=libc++
cmake --build build
./build/main

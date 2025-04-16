#!/usr/bin/env bash

export CC=clang
export CC_LD=lld

# meson init main.c hello.c

mkdir -p build && cd build || exit

meson setup ..
meson compile

./src/hello2
./src/hello2 version

# ./hello foo bar baz

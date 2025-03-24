cmake_minimum_required(VERSION 3.12)

project(CppCon2020 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # use `-std=c++20` instead of `--std=gnu++20`

set(CMAKE_CXX_SCAN_FOR_MODULES YES)
set(CMAKE_EXECUTABLE_ENABLE_EXPORTS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

add_compile_options(
    #-Werror
    -Wall
    -Wextra
)

file(GLOB sources "*.cpp")
foreach(source IN LISTS sources)
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
endforeach()

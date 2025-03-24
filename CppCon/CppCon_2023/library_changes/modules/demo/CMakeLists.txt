# https://libcxx.llvm.org/Modules.html#using-the-installed-modules
#
# This requires a recent nightly build.
# This will be part of CMake 3.30.0.
cmake_minimum_required(VERSION 3.29.0 FATAL_ERROR)

# Enables the Standard module support. This needs to be done
# before selecting the languages.
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
set(CMAKE_CXX_MODULE_STD ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
# Currently CMake requires extensions enabled when using import std.
# https://gitlab.kitware.com/cmake/cmake/-/issues/25916
# https://gitlab.kitware.com/cmake/cmake/-/issues/25539
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_EXECUTABLE_ENABLE_EXPORTS TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(CppCon2023 LANGUAGES CXX)

add_compile_options(
    #-Werror
    -Wall
    -Wextra
)


add_executable(main)
target_sources(main
  PRIVATE
    main.cpp
)

# file(GLOB sources "*.cpp")
# foreach(source IN LISTS sources)
#     get_filename_component(name ${source} NAME_WE)
#     add_executable(${name} ${source})
# endforeach()

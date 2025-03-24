cmake_minimum_required(VERSION 3.28)

project(CppCon2020 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # use `-std=c++20` instead of `--std=gnu++20`

set(CMAKE_CXX_SCAN_FOR_MODULES YES)
set(CMAKE_EXECUTABLE_ENABLE_EXPORTS TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# https://clang.llvm.org/docs/Modules.html#id19
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules") # enable moudles
endif()

add_compile_options(
    #-Werror
    -Wall
    -Wextra
)

add_executable(main main.cpp)
target_sources(main
  PUBLIC
    FILE_SET cppcon TYPE CXX_MODULES FILES
    cppcon.cppm
)

# file(GLOB sources "*.cpp")
# foreach(source IN LISTS sources)
#     get_filename_component(name ${source} NAME_WE)
#     add_executable(${name} ${source})
# endforeach()

cmake_minimum_required(VERSION 3.12)

project(CppCon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # use `-std=c++20` instead of `--std=gnu++20`

set(CMAKE_EXECUTABLE_ENABLE_EXPORTS TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

add_compile_options(
    #-Werror
    -Wall
    -Wextra
)

set(sources
    main.cpp
    main2.cpp
    main3.cpp
    # main4.cpp
    # main5.cpp
    # main6.cpp
    # main7.cpp
    # main8.cpp
    # main9.cpp
    main10.cpp
    main11.cpp
    # main12.cpp
)

# file(GLOB sources "*.cpp")
foreach(source IN LISTS sources)
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
endforeach()

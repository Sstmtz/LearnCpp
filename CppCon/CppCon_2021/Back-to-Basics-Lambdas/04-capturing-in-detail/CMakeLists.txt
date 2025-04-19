cmake_minimum_required(VERSION 3.12)

project(LearnCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXECUTABLE_ENABLE_EXPORTS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for generating compile_command.json

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# enable color diagnostics
if(CMAKE_VERSION VERSION_LESS "3.24")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
else()
    set(CMAKE_COLOR_DIAGNOSTICS ON)
endif()

# add link flags
if(CMAKE_VERSION VERSION_LESS "3.29")
    set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -fuse-ld=lld")
    set(CMAKE_C_LINK_EXECUTABLE "${CMAKE_C_LINK_EXECUTABLE} -fuse-ld=lld")
else()
    set(CMAKE_LINKER_TYPE LLD)
endif()

add_compile_options(
    #-Werror
    -Wall
    -Wextra
    -Wno-unknown-warning-option
    # -Wno-unused-parameter
    # -Wno-unused-variable
    # -Wno-interference-size
    # -Wno-missing-field-initializers
    # -Wno-shadow
    # -Wno-pointer-arith
    -Werror=vla
    # -Werror=multichar
    # -Werror=overflow
    -Werror=restrict
    # -Werror=address
    # -Werror=narrowing
    # -Werror=reorder
    -Werror=div-by-zero
    # -Werror=unused-result
    -Werror=return-type
    # -Werror=return-local-addr
    # -Werror=missing-declarations
    # -Werror=delete-non-virtual-dtor
    # -Werror=suggest-override
    # -Werror=conversion-null
    # -Werror=mismatched-new-delete
    # -Werror=array-bounds
    # -Werror=zero-length-bounds
    # -Werror=dangling-pointer=2
    # -Werror=class-memaccess
    # -Werror=bool-compare -Werror=bool-operation
    # -Werror=deprecated-copy -Werror=deprecated-copy-dtor
)

set(sources
    main.cpp
    main2.cpp
    main3.cpp
    # main4.cpp
    main5.cpp
)

# file(GLOB sources "*.cpp")
foreach(source IN LISTS sources)
    get_filename_component(name ${source} NAME_WE)
    add_executable(${name} ${source})
endforeach()

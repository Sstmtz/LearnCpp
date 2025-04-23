# https://json.nlohmann.me/integration/cmake/

# 1. External
cmake_minimum_required(VERSION 3.5)
project(ExampleProject LANGUAGES CXX)

find_package(nlohmann_json 3.12.0 REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

# 2. Embedded
# cmake_minimum_required(VERSION 3.5)
# project(ExampleProject LANGUAGES CXX)
#
# # If you only include this third party in PRIVATE source files, you do not need to install it
# # when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")
#
# add_subdirectory(nlohmann_json)
#
# add_executable(example example.cpp)
# target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

# 3. FetchContent
# cmake_minimum_required(VERSION 3.11)
# project(ExampleProject LANGUAGES CXX)
#
# include(FetchContent)

# by downloading a release as dependency
# FetchContent_Declare(json
#     URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
# )

# by cloning the git repo
# FetchContent_Declare(json
#     GIT_REPOSITORY https://github.com/nlohmann/json
#     GIT_TAG v3.12.0
# )

# FetchContent_MakeAvailable(json)
#
# add_executable(example example.cpp)
# target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

# 4. CPM.cmake
# cmake_minimum_required(VERSION 3.15)
# project(json_example)
#
# include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)
#
# CPMAddPackage("gh:nlohmann/json@3.12.0")
#
# add_executable(example example.cpp)
# target_link_libraries(example PRIVATE nlohmann_json::nlohmann_json)

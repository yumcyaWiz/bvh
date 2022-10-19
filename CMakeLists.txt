cmake_minimum_required(VERSION 3.20)
project(mcrt-intro LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ version and std
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# OpenMP
find_package(OpenMP REQUIRED)

# externals
add_subdirectory("externals/")

# bvh
add_library(bvh INTERFACE)
target_include_directories(bvh INTERFACE "include/")
target_link_libraries(bvh INTERFACE glm)

# apps
add_subdirectory("apps/")
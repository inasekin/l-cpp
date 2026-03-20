cmake_minimum_required(VERSION 3.16)
project(LabClasses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(logger STATIC 01task/logger.cpp)
target_include_directories(logger PUBLIC 01task)

add_subdirectory(01task)
add_subdirectory(02task)
add_subdirectory(03task)
add_subdirectory(04task)
add_subdirectory(05task)
add_subdirectory(06task)

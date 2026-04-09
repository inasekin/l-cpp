cmake_minimum_required(VERSION 3.16)
project(LabFunc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0
)
FetchContent_MakeAvailable(spdlog)

include_directories(include)
add_compile_definitions(LOGS_DIR="${CMAKE_SOURCE_DIR}/logs")

add_library(figure_lib
        src/figure.cpp
        src/circle.cpp
        src/rectangle.cpp
)
target_link_libraries(figure_lib PRIVATE spdlog::spdlog)

add_subdirectory(01_task)
add_subdirectory(02_task)
add_subdirectory(03_task)
add_subdirectory(04_task)
add_subdirectory(05_task)
add_subdirectory(06_task)
add_subdirectory(07_task)
add_subdirectory(08_task)
add_subdirectory(09_task)
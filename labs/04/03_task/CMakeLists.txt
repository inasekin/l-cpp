set(SOURCES
        main.cpp
)

add_executable(03_task ${SOURCES})

target_include_directories(03_task PRIVATE .)
target_link_libraries(03_task PRIVATE figure_lib spdlog::spdlog)
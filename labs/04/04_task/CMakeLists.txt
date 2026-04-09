set(SOURCES
        main.cpp
)

add_executable(04_task ${SOURCES})

target_include_directories(04_task PRIVATE .)
target_link_libraries(04_task PRIVATE figure_lib spdlog::spdlog)
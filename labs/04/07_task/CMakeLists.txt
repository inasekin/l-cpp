set(SOURCES
        main.cpp
)

add_executable(07_task ${SOURCES})

target_include_directories(07_task PRIVATE .)
target_link_libraries(07_task PRIVATE figure_lib spdlog::spdlog)
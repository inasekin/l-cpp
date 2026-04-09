set(SOURCES
        main.cpp
)

add_executable(05_task ${SOURCES})

target_include_directories(05_task PRIVATE .)
target_link_libraries(05_task PRIVATE figure_lib spdlog::spdlog)
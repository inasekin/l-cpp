set(SOURCES
        main.cpp
)

add_executable(02_task ${SOURCES})

target_include_directories(02_task PRIVATE .)
target_link_libraries(02_task PRIVATE figure_lib spdlog::spdlog)
set(SOURCES
        main.cpp
)

add_executable(06_task ${SOURCES})

target_include_directories(06_task PRIVATE .)
target_link_libraries(06_task PRIVATE figure_lib spdlog::spdlog)
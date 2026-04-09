set(SOURCES
        main.cpp
)

add_executable(09_task ${SOURCES})

target_include_directories(09_task PRIVATE .)
target_link_libraries(09_task PRIVATE figure_lib spdlog::spdlog)
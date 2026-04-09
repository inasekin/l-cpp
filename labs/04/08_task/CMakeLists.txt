set(SOURCES
        main.cpp
)

add_executable(08_task ${SOURCES})

target_include_directories(08_task PRIVATE .)
target_link_libraries(08_task PRIVATE figure_lib spdlog::spdlog)
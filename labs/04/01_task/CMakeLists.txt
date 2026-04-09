set(SOURCES
        main.cpp
)

add_executable(01_task ${SOURCES})

target_include_directories(01_task PRIVATE .)
target_link_libraries(01_task PRIVATE figure_lib spdlog::spdlog)
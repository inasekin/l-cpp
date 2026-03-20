set(SOURCES
        main.cpp
        tracked_string.cpp
)

add_executable(06task ${SOURCES})
target_link_libraries(06task PRIVATE logger)
target_compile_definitions(06task PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task06.log"
)

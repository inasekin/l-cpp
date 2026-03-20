set(SOURCES
        main.cpp
        tracked_string.cpp
)

add_executable(02task ${SOURCES})

target_link_libraries(02task PRIVATE logger)

target_compile_definitions(02task PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task02.log"
)

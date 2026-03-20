set(SOURCES
        main.cpp
        tracked_string.cpp
)

add_executable(05task ${SOURCES})

target_link_libraries(05task PRIVATE logger)

target_compile_definitions(05task PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task05.log"
)

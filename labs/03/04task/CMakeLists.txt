set(SOURCES
    main.cpp
    tracked_string.cpp
)

add_executable(04task ${SOURCES})

target_link_libraries(04task PRIVATE logger)

target_compile_definitions(04task PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task04.log"
)

set(SOURCES
        main.cpp
        logger.cpp
)

add_executable(01task ${SOURCES})

target_link_libraries(01task PRIVATE logger)

target_compile_definitions(01task PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task01.log"
)

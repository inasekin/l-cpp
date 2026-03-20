set(SOURCES
        main.cpp
        src/benchmark.cpp
        src/utils.cpp
)

add_executable(02_task ${SOURCES})

target_include_directories(02_task PRIVATE .)
target_compile_definitions(02_task PRIVATE
        RESULTS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/results"
)
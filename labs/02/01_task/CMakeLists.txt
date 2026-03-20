set(SOURCES
        main.cpp
        src/benchmark.cpp
        src/utils.cpp
)

add_executable(01_task ${SOURCES})

target_include_directories(01_task PRIVATE .)
target_compile_definitions(01_task PRIVATE
        RESULTS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/results"
)
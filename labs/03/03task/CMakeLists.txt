add_executable(03task_a main.cpp wrapper_a.cpp tracked_string.cpp)

target_link_libraries(03task_a PRIVATE logger)
target_compile_definitions(03task_a PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task03_a.log"
)

add_executable(03task_b main.cpp wrapper_b.cpp tracked_string.cpp)

target_link_libraries(03task_b PRIVATE logger)
target_compile_definitions(03task_b PRIVATE
    LOG_FILE="${CMAKE_SOURCE_DIR}/logs/task03_b.log"
)

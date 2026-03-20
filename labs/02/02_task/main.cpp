//
// Created by Иван Насекин on 22.02.2026.
//

#include "include/benchmark.h"
#include "include/utils.h"

int main() {
    const auto data = generate_data(32768);

    measure_deque_push_back(data);
    measure_deque_push_front(data);
    measure_deque_random_insert(data);
    measure_deque_random_erase(data);
    measure_deque_random_access(data);

    return 0;
}
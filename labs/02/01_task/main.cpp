//
// Created by Иван Насекин on 21.02.2026.
//

#include "include/benchmark.h"
#include "include/utils.h"

int main() {
    const auto data = generate_data(32768);

    measure_push_back(data);
    measure_push_front(data);
    measure_random_insert(data);
    measure_random_erase(data);
    measure_random_access(data);

    return 0;
}

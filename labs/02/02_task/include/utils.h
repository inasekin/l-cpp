#pragma once

#include <string>
#include <vector>

struct DequeResult {
    int n;
    long long time_ns;
    std::size_t size;
};

std::vector<int> generate_data(std::size_t max_size);
void write_deque_results(const std::string& filename, const std::vector<DequeResult>& results);
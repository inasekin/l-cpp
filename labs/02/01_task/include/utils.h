//
// Created by Иван Насекин on 21.02.2026.
//

#pragma once

#include <string>
#include <vector>

struct Result {
    int n;
    long long time_ns;
    std::size_t size;
    std::size_t capacity;
};

std::vector<int> generate_data(std::size_t max_size);
void write_results(const std::string& filename, const std::vector<Result>& results);
#include "include/utils.h"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <random>

std::vector<int> generate_data(std::size_t max_size) {
    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> dist(0, 1'000'000);
    std::vector<int> data(max_size);
    for (auto& x : data) {
        x = dist(rng);
    }
    return data;
}

void write_results(const std::string& filename, const std::vector<Result>& results) {
    std::filesystem::create_directories(std::filesystem::path(filename).parent_path());
    std::ofstream out(filename);
    out << std::left << std::setw(10) << "N" << std::setw(15) << "Time (ns)"
        << std::setw(10) << "size" << "capacity\n";
    for (const auto& r : results) {
        out << std::left << std::setw(10) << r.n << std::setw(15) << r.time_ns
            << std::setw(10) << r.size << r.capacity << "\n";
    }
}
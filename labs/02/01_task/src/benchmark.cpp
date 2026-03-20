#include "include/benchmark.h"
#include "include/utils.h"

#include <chrono>
#include <string>
#include <vector>

static const int sizes[] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

#ifndef RESULTS_DIR
#define RESULTS_DIR "results"
#endif

template <typename Op>
static std::vector<Result> run_bench(const std::vector<int>& data, Op op) {
    std::vector<Result> res;
    for (int n : sizes) {
        long long total = 0;
        std::size_t sz = 0, cap = 0;
        for (int i = 0; i < 50; i++) {
            std::vector<int> v(data.begin(), data.begin() + n);
            v.shrink_to_fit();

            auto t0 = std::chrono::steady_clock::now();
            op(v, data[0]);
            auto t1 = std::chrono::steady_clock::now();

            total += std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
            sz = v.size();
            cap = v.capacity();
        }
        res.push_back({n, total / 50, sz, cap});
    }
    return res;
}

void measure_push_back(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::vector<int>& v, int x) {
        v.push_back(x);
    });
    write_results(std::string(RESULTS_DIR) + "/vector_push_back.txt", res);
}

void measure_push_front(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::vector<int>& v, int x) {
        v.insert(v.begin(), x);
    });
    write_results(std::string(RESULTS_DIR) + "/vector_push_front.txt", res);
}

void measure_random_insert(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::vector<int>& v, int x) {
        v.insert(v.begin() + 9, x);
    });
    write_results(std::string(RESULTS_DIR) + "/vector_random_insert.txt", res);
}

void measure_random_erase(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::vector<int>& v, int) {
        v.erase(v.begin() + 9);
    });
    write_results(std::string(RESULTS_DIR) + "/vector_random_erase.txt", res);
}

void measure_random_access(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::vector<int>& v, int) {
        int tmp = v[9];
        v[9] = tmp;
    });
    write_results(std::string(RESULTS_DIR) + "/vector_random_access.txt", res);
}

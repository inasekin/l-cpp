#include "include/benchmark.h"
#include "include/utils.h"

#include <chrono>
#include <deque>
#include <string>
#include <vector>

static const int sizes[] = {256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

#ifndef RESULTS_DIR
#define RESULTS_DIR "results"
#endif

template <typename Op>
static std::vector<DequeResult> run_bench(const std::vector<int>& data, Op op) {
    std::vector<DequeResult> res;
    for (int n : sizes) {
        long long total = 0;
        std::size_t sz = 0;
        for (int i = 0; i < 50; i++) {
            std::deque<int> dq(data.begin(), data.begin() + n);

            auto t0 = std::chrono::steady_clock::now();
            op(dq, data[0]);
            auto t1 = std::chrono::steady_clock::now();

            total += std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
            sz = dq.size();
        }
        res.push_back({n, total / 50, sz});
    }
    return res;
}

void measure_deque_push_back(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::deque<int>& dq, int x) {
        dq.push_back(x);
    });
    write_deque_results(std::string(RESULTS_DIR) + "/deque_push_back.txt", res);
}

void measure_deque_push_front(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::deque<int>& dq, int x) {
        dq.push_front(x);
    });
    write_deque_results(std::string(RESULTS_DIR) + "/deque_push_front.txt", res);
}

void measure_deque_random_insert(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::deque<int>& dq, int x) {
        dq.insert(dq.begin() + 9, x);
    });
    write_deque_results(std::string(RESULTS_DIR) + "/deque_random_insert.txt", res);
}

void measure_deque_random_erase(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::deque<int>& dq, int) {
        dq.erase(dq.begin() + 9);
    });
    write_deque_results(std::string(RESULTS_DIR) + "/deque_random_erase.txt", res);
}

void measure_deque_random_access(const std::vector<int>& vec) {
    auto res = run_bench(vec, [](std::deque<int>& dq, int) {
        int tmp = dq[9];
        dq[9] = tmp;
    });
    write_deque_results(std::string(RESULTS_DIR) + "/deque_random_access.txt", res);
}

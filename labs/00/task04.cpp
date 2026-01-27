//
// Created by Иван Насекин on 23.01.2026.
//

#include <chrono>
#include <iomanip>
#include <iostream>

const size_t SIZE_O = 100'000'000;

template <typename T, typename Op>
double checkTime(T initial, Op operation) {
    volatile T x = initial;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < SIZE_O; ++i) {
        x = initial;
        x = operation(x);

        //asm volatile("" : "+r" (x) : : "memory");
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

void tests() {
        std::cout << std::left << std::setw(25) << "Тип данных"
              << std::setw(25) << "Операция"
              << std::setw(25) << "Арифметическая"
              << std::setw(25) << "Битовая" << '\n';

    int32_t val_int = 123456789;

    double t_int_div_arith = checkTime<int32_t>(val_int, [](int32_t v){ return v / 2; });
    double t_int_div_bit = checkTime<int32_t>(val_int, [](int32_t v){ return v >> 1; });
    std::cout << std::setw(10) << "int32_t" << std::setw(20) << "Деление на 2 " << std::setw(25) << t_int_div_arith << std::setw(25) << t_int_div_bit << '\n';

    double t_int_mul_arith = checkTime<int32_t>(val_int, [](int32_t v){ return v * 2; });
    double t_int_mul_bit = checkTime<int32_t>(val_int, [](int32_t v){ return v << 1; });
    std::cout << std::setw(10) << "int32_t" << std::setw(20) << "Умножение на 2 " << std::setw(25) << t_int_mul_arith << std::setw(25) << t_int_mul_bit << '\n';

    double t_int_parity_arith = checkTime<int32_t>(val_int, [](int32_t v){ return (v % 2) == 0; });
    double t_int_parity_bit = checkTime<int32_t>(val_int, [](int32_t v){ return (v & 1) == 0; });
    std::cout << std::setw(10) << "int32_t" << std::setw(20) << "Четность " << std::setw(25) << t_int_parity_arith << std::setw(25) << t_int_parity_bit << '\n';

    uint32_t val_uint = 123456789U;

    double t_uint_div_arith = checkTime<uint32_t>(val_uint, [](uint32_t v){ return v / 2; });
    double t_uint_div_bit = checkTime<uint32_t>(val_uint, [](uint32_t v){ return v >> 1; });
    std::cout << std::setw(10) << "uint32_t" << std::setw(20) << "Деление на 2 " << std::setw(25) << t_uint_div_arith << std::setw(25) << t_uint_div_bit << '\n';

    double t_uint_mul_arith = checkTime<uint32_t>(val_uint, [](uint32_t v){ return v * 2; });
    double t_uint_mul_bit = checkTime<uint32_t>(val_uint, [](uint32_t v){ return v << 1; });
    std::cout << std::setw(10) << "uint32_t" << std::setw(20) << "Умножение на 2 " << std::setw(25) << t_uint_mul_arith << std::setw(25) << t_uint_mul_bit << '\n';

    double t_uint_parity_arith = checkTime<uint32_t>(val_uint, [](uint32_t v){ return (v % 2) == 0; });
    double t_uint_parity_bit = checkTime<uint32_t>(val_uint, [](uint32_t v){ return (v & 1) == 0; });
    std::cout << std::setw(10) << "uint32_t" << std::setw(20) << "Четность " << std::setw(25) << t_uint_parity_arith << std::setw(25) << t_uint_parity_bit << '\n';
}

int main () {
    tests();
}
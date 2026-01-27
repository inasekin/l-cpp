//
// Created by Иван Насекин on 22.01.2026.
//

#include <iostream>

void print_bits(int32_t x) {
    for (int i = 31; i >= 0; i--) {
        std::cout << ((x >> i) & 1);
    }
    std::cout << '\n';
}

void bit_operations(int a, int b) {
    std::cout << (a & b) << '\n';
    std::cout << (a | b) << '\n';
    std::cout << (a ^ b) << '\n';
    std::cout << (~a) << '\n';
    std::cout << (a << 2) << (a >> 2) << '\n';
    std::cout << (b << 2) << (b >> 2) << '\n';
}

int main() {
    print_bits(42);
    print_bits(-17);
    bit_operations(42, -17);

    return 0;
}
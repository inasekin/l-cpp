//
// Created by Иван Насекин on 22.01.2026.
//
#include <iostream>

void testOverflow() {
    std::cout << UINT32_MAX + 2 << '\n';
    std::cout << INT32_MAX + 2 << '\n';
}

int main() {
    testOverflow();

    return 0;
}
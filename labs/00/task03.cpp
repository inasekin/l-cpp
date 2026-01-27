//
// Created by Иван Насекин on 22.01.2026.
//
#include <iomanip>
#include <iostream>

void numRepresentation() {
    float a = 10.25f;
    float b = 7.1f;
    float sum = a + b;

    std::cout << std::setprecision(12) << sum << '\n';
}

void violationOfAssociativity() {
    float a = 16'777'216.0f;
    float b = 1.0f;
    float c = 1.0f;

    float res1 = (a + b) + c;
    float res2 = a + (b + c);

    std::cout << "(a + b) + c = " << res1 << '\n';
    std::cout << "a + (b + c) = " << res2 << '\n';
}

void comparison() {
    double x = 0.1 + 0.2;
    float y = 0.1 + 0.2;

    std::cout << x << '\n';
    std::cout << y << '\n';

    if (x == 0.3) {
        std::cout << "Равны" << '\n';
    } else {
        std::cout << "Не равны" << '\n';
    }

    if (y == 0.3) {
        std::cout << "Равны" << '\n';
    } else {
        std::cout << "Не равны" << '\n';
    }
}

int main() {
    numRepresentation();
    violationOfAssociativity();
    comparison();

    return 0;
}
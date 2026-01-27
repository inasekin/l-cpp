#include <chrono>
#include <iomanip>
#include <iostream>

const size_t N = 100'000'000;

template <typename T>
double checkTimeWithVolatile() {
    volatile T x = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < N; ++i) {
        x += 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

template <typename T>
double checkTimeWithoutVolatile() {
    T x = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < N; ++i) {
        x += 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;

    return duration.count();
}

void tests() {
    std::cout << std::left << std::setw(25) << "Тип"
              << std::setw(25) << "Размер типа (байт)"
              << std::setw(25) << "Время (мкс)" << '\n';

    std::cout << std::setw(25) << "char" << std::setw(25) << sizeof(char)
              << std::setw(25) << checkTimeWithVolatile<char>() << '\n';

    std::cout << std::setw(25) << "short" << std::setw(25) << sizeof(short)
              << std::setw(25) << checkTimeWithVolatile<short>() << '\n';

    std::cout << std::setw(25) << "int" << std::setw(25) << sizeof(int)
              << std::setw(25) << checkTimeWithVolatile<int>() << '\n';

    std::cout << std::setw(25) << "unsigned char" << std::setw(25) << sizeof(unsigned char)
              << std::setw(25) << checkTimeWithVolatile<unsigned char>() << '\n';

    std::cout << std::setw(25) << "unsigned short" << std::setw(25) << sizeof(unsigned short)
              << std::setw(25) << checkTimeWithVolatile<unsigned short>() << '\n';

    std::cout << std::setw(25) << "unsigned int" << std::setw(25) << sizeof(unsigned int)
              << std::setw(25) << checkTimeWithVolatile<unsigned int>() << '\n';

    std::cout << std::setw(25) << "float" << std::setw(25) << sizeof(float)
              << std::setw(25) << checkTimeWithVolatile<float>() << '\n';

    std::cout << std::setw(25) << "double" << std::setw(25) << sizeof(double)
              << std::setw(25) << checkTimeWithVolatile<double>() << '\n';

    std::cout << std::left << std::setw(25) << "Тип"
              << std::setw(25) << "Размер типа (байт)"
              << std::setw(25) << "Время (мкс)" << '\n';

    std::cout << std::setw(25) << "char" << std::setw(25) << sizeof(char)
              << std::setw(25) << checkTimeWithoutVolatile<char>() << '\n';

    std::cout << std::setw(25) << "short" << std::setw(25) << sizeof(short)
              << std::setw(25) << checkTimeWithoutVolatile<short>() << '\n';

    std::cout << std::setw(25) << "int" << std::setw(25) << sizeof(int)
              << std::setw(25) << checkTimeWithoutVolatile<int>() << '\n';

    std::cout << std::setw(25) << "unsigned char" << std::setw(25) << sizeof(unsigned char)
              << std::setw(25) << checkTimeWithoutVolatile<unsigned char>() << '\n';

    std::cout << std::setw(25) << "unsigned short" << std::setw(25) << sizeof(unsigned short)
              << std::setw(25) << checkTimeWithoutVolatile<unsigned short>() << '\n';

    std::cout << std::setw(25) << "unsigned int" << std::setw(25) << sizeof(unsigned int)
              << std::setw(25) << checkTimeWithoutVolatile<unsigned int>() << '\n';

    std::cout << std::setw(25) << "float" << std::setw(25) << sizeof(float)
              << std::setw(25) << checkTimeWithoutVolatile<float>() << '\n';

    std::cout << std::setw(25) << "double" << std::setw(25) << sizeof(double)
              << std::setw(25) << checkTimeWithoutVolatile<double>() << '\n';
}

int main() {
    tests();
}
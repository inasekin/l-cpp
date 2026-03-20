//
// Created by Иван Насекин on 09.03.2026.
//

#include "logger.h"
#include "tracked_string.h"

#include <iostream>

int main() {
    Logger::getInstance(LOG_FILE).setLevel(Level::DEBUG);

    TrackedString a("hello");
    TrackedString b("world");

    std::cout << a << " " << b << "\n";

    auto c = a + b;
    std::cout << c << "\n";

    std::cout << std::boolalpha << (a == b) << " " << (a < b) << '\n';

    return 0;
}

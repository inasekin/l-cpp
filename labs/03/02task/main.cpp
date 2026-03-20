//
// Created by Иван Насекин on 08.03.2026.
//

#include "logger.h"
#include "tracked_string.h"

#include <string>

int main() {
    Logger::getInstance(LOG_FILE).setLevel(Level::DEBUG);

    TrackedString a;
    TrackedString b("hello");
    std::string s = "world";
    TrackedString c(s);
    TrackedString d = c;

    return 0;
}

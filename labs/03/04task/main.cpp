//
// Created by Иван Насекин on 08.03.2026.
//

#include "logger.h"
#include "tracked_string.h"

int main() {
    Logger::getInstance(LOG_FILE).setLevel(Level::DEBUG);

    TrackedString x;
    TrackedString y("test");

    return 0;
}

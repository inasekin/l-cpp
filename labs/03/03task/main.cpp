//
// Created by Иван Насекин on 08.03.2026.
//

#include "logger.h"
#include "wrapper.h"

int main() {
    Logger::getInstance(LOG_FILE).setLevel(Level::DEBUG);

    Wrapper w("hello");

    return 0;
}

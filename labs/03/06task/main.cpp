//
// Created by Иван Насекин on 09.03.2026.
//

#include "logger.h"
#include "tracked_string.h"

#include <vector>

int main() {
    Logger::getInstance(LOG_FILE).setLevel(Level::DEBUG);

    std::vector<TrackedString> vec;

    vec.push_back(TrackedString("temp"));
    TrackedString ts("str");
    vec.push_back(ts);
    vec.emplace_back("temp");
    vec.emplace_back(TrackedString("temp"));

    return 0;
}

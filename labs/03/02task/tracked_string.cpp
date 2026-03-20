//
// Created by Иван Насекин on 08.03.2026.
//

#include "tracked_string.h"

#include <utility>
#include "logger.h"

int TrackedString::counter_ = 0;

TrackedString::TrackedString() : id_(++counter_) {
    Logger::getInstance(LOG_FILE).log(
        "[конструктор по умолчанию] id=" + std::to_string(id_),
        Level::INFO);
}

TrackedString::TrackedString(std::string  s) : value_(std::move(s)), id_(++counter_) {
    Logger::getInstance(LOG_FILE).log(
        "[строковый конструктор] id=" + std::to_string(id_) + " значение=" + value_,
        Level::INFO);
}

TrackedString::TrackedString(const char* s) : value_(s), id_(++counter_) {
    Logger::getInstance(LOG_FILE).log(
        "[char* конструктор] id=" + std::to_string(id_) + " значение=" + value_,
        Level::INFO);
}

TrackedString::TrackedString(const TrackedString& other) : value_(other.value_), id_(++counter_) {
    Logger::getInstance(LOG_FILE).log(
        "[копирующий конструктор] id=" + std::to_string(id_) + " from id=" + std::to_string(other.id_),
        Level::INFO);
}

TrackedString::~TrackedString() {
    Logger::getInstance(LOG_FILE).log(
        "[деструктор] id=" + std::to_string(id_),
        Level::INFO);
}

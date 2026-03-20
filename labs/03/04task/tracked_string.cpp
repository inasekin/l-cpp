//
// Created by Иван Насекин on 08.03.2026.
//

#include "tracked_string.h"
#include "logger.h"

int TrackedString::counter_ = 0;

TrackedString::TrackedString(std::string s) : value_(std::move(s)), id_(++counter_) {
    Logger::getInstance(LOG_FILE).log(
        "[строковый конструктор] id=" + std::to_string(id_) + " значение=" + value_,
        Level::INFO);
}

TrackedString::TrackedString(const char* s) : TrackedString(std::string(s)) {
    Logger::getInstance(LOG_FILE).log(
        "[char* конструктор делегирован] id=" + std::to_string(id_),
        Level::INFO);
}

TrackedString::TrackedString() : TrackedString("") {
    Logger::getInstance(LOG_FILE).log(
        "[конструктор по умолчанию делегирован] id=" + std::to_string(id_),
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

//
// Created by Иван Насекин on 07.03.2026.
//

#include "logger.h"

#include <chrono>
#include <ctime>
#include <filesystem>
#include <iomanip>
#include <iostream>

// чуть подсмотрел логику тут https://radioprog.ru/post/1470
// https://habr.com/ru/articles/147373/

Logger::Logger(const std::string& filename) : current_level_(Level::DEBUG) {
    auto parent = std::filesystem::path(filename).parent_path();
    if (!parent.empty()) {
        std::filesystem::create_directories(parent);
    }

    file_.open(filename, std::ios::out);
    if (!file_.is_open()) {
        std::cerr << "Logger: не удалось открыть файл: " << filename << "\n";
    }
}

Logger::~Logger() {
    if (file_.is_open()) {
        file_.close();
    }
}

Logger& Logger::getInstance(const std::string& filename) {
    static Logger instance(filename);
    return instance;
}

void Logger::log(const std::string& message, int level) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::lock_guard lock(mutex_);

    if (level > current_level_) {
        return;
    }

    if (file_.is_open()) {
        file_ << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S")
              << " [" << levelToString(level) << "] "
              << message << "\n";
        file_.flush();
    }
}

void Logger::setLevel(int level) {
    std::lock_guard lock(mutex_);
    current_level_ = level;
}

std::string Logger::levelToString(int level) {
    switch (level) {
        case Level::ERROR:   return "ERROR";
        case Level::WARNING: return "WARNING";
        case Level::INFO:    return "INFO";
        case Level::DEBUG:   return "DEBUG";
        default:             return "INFO";
    }
}

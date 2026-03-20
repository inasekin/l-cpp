//
// Created by Иван Насекин on 07.03.2026.
//

#pragma once

#include <fstream>
#include <mutex>
#include <string>

class Level {
public:
    static const int ERROR   = 0;
    static const int WARNING = 1;
    static const int INFO    = 2;
    static const int DEBUG   = 3;
};

class Logger {
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance(const std::string& filename = "task.log");

    void log(const std::string& message, int level);
    void setLevel(int level);

private:
    explicit Logger(const std::string& filename);
    ~Logger();

    static std::string levelToString(int level);

    std::ofstream file_;
    int current_level_;
    std::mutex mutex_;
};

//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "figure.h"
#include <string>
#include <filesystem>

class FigureNonVirtual {
public:
    FigureNonVirtual() : name("FigureNonVirtual") {}
    ~FigureNonVirtual() {}

    double area() const { return 0.0; }
    double perimetr() const { return 0.0; }
    void info() const {}

protected:
    std::string name;
};

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task04_logger", LOGS_DIR "/task04.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    spdlog::info("sizeof(Figure)           = {}", sizeof(Figure));
    spdlog::info("sizeof(FigureNonVirtual) = {}", sizeof(FigureNonVirtual));
    spdlog::info("sizeof(void*)            = {}", sizeof(void*));
    spdlog::info("sizeof(std::string)      = {}", sizeof(std::string));

    return 0;
}

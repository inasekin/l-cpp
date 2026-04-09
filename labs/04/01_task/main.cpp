//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include <filesystem>

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task01_logger", LOGS_DIR "/task01.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    Circle c(5.0);
    Rectangle r(3.0, 4.0);

    spdlog::info("c.area() = {:.4f}", c.area());
    spdlog::info("c.perimetr() = {:.4f}", c.perimetr());
    c.info();

    spdlog::info("r.area() = {:.4f}", r.area());
    spdlog::info("r.perimetr() = {:.4f}", r.perimetr());
    r.info();

    Figure* pc = &c;
    Figure* pr = &r;

    spdlog::info("pc->area() = {:.4f}", pc->area());
    spdlog::info("pc->perimetr() = {:.4f}", pc->perimetr());
    pc->info();

    spdlog::info("pr->area() = {:.4f}", pr->area());
    spdlog::info("pr->perimetr() = {:.4f}", pr->perimetr());
    pr->info();

    return 0;
}

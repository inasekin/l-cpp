//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "figure.h"
#include "circle.h"
#include "rectangle.h"
#include <vector>
#include <filesystem>

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task02_logger", LOGS_DIR "/task02.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    std::vector<Figure*> figures;
    figures.push_back(new Circle(5.0));
    figures.push_back(new Rectangle(3.0, 4.0));
    figures.push_back(new Circle(2.0));

    for (Figure* f : figures) {
        spdlog::info("area={:.4f}, perimetr={:.4f}", f->area(), f->perimetr());
        f->info();
    }

    for (Figure* f : figures) {
        delete f;
    }

    std::vector<Circle> circles;
    circles.emplace_back(1.0);
    circles.emplace_back(2.0);
    circles.emplace_back(3.0);

    for (Circle& obj : circles) {
        spdlog::info("area={:.4f}, perimetr={:.4f}", obj.area(), obj.perimetr());
        obj.info();
    }

    Circle sliceDemo(7.0);
    Figure& fRef = sliceDemo;
    spdlog::info("fRef.area() = {:.4f}", fRef.area());
    fRef.info();

    return 0;
}

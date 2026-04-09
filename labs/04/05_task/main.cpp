//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <string>
#include <filesystem>

class Figure5 {
public:
    Figure5() : name("Figure5") { spdlog::info("Figure5 constructor"); }
    virtual ~Figure5() { spdlog::debug("Figure5 destructor"); }

    virtual double area() const { return 0.0; }
    virtual void info() const {
        spdlog::info("Figure5::info() -> area={:.4f}", area());
    }

protected:
    std::string name;
};

class Circle5 : public Figure5 {
public:
    explicit Circle5(double r) : radius(r) {
        name = "Circle5";
        spdlog::info("Circle5 constructor, radius={}", r);
    }
    ~Circle5() override { spdlog::debug("Circle5 destructor, radius={}", radius); }

    double area() const override { return M_PI * radius * radius; }
    void info() const override {
        spdlog::info("Circle5::info() -> radius={}, area={:.4f}", radius, area());
    }

private:
    double radius;
};

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task05_logger", LOGS_DIR "/task05.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    Circle5 c(5.0);

    Figure5* ptr = &c;
    spdlog::info("ptr->area() = {:.4f}", ptr->area());
    ptr->info();

    Figure5 sliced = c;
    spdlog::info("sliced.area() = {:.4f}", sliced.area());
    sliced.info();

    spdlog::info("sizeof(Circle5) = {}", sizeof(Circle5));
    spdlog::info("sizeof(Figure5) = {}", sizeof(Figure5));

    return 0;
}

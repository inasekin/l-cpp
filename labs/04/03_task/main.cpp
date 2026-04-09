//
// Created by Иван Насекин on 23.03.2026.
//

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include <vector>
#include <filesystem>

class Figure3 {
public:
    Figure3() { spdlog::info("Figure3 constructor"); }
    virtual ~Figure3() { spdlog::debug("Figure3 destructor"); }

    virtual double area() const = 0;
    virtual double perimetr() const { return 0.0; }
    virtual void info() const {
        spdlog::info("Figure3::info() -> area={:.4f}, perimetr={:.4f}", area(), perimetr());
    }
};

class Circle3 : public Figure3 {
public:
    explicit Circle3(double r) : radius(r) {
        spdlog::info("Circle3 constructor, radius = {}", r);
    }
    ~Circle3() override { spdlog::debug("Circle3 destructor, radius = {}", radius); }

    double area() const override { return M_PI * radius * radius; }
    double perimetr() const override { return 2.0 * M_PI * radius; }
    void info() const override {
        spdlog::info("Circle3::info() -> radius={}, area={:.4f}, perimetr={:.4f}",
                     radius, area(), perimetr());
    }

private:
    double radius;
};

class Rectangle3 : public Figure3 {
public:
    Rectangle3(double w, double h) : width(w), height(h) {
        spdlog::info("Rectangle3 constructor, {}x{}", w, h);
    }
    ~Rectangle3() override { spdlog::debug("Rectangle3 destructor, {}x{}", width, height); }

    double area() const override { return width * height; }
    double perimetr() const override { return 2.0 * (width + height); }
    void info() const override {
        spdlog::info("Rectangle3::info() -> {}x{}, area={:.4f}, perimetr={:.4f}",
                     width, height, area(), perimetr());
    }

private:
    double width, height;
};

int main() {
    std::filesystem::create_directories(LOGS_DIR);
    auto logger = spdlog::basic_logger_mt("task03_logger", LOGS_DIR "/task03.log", true);
    logger->set_level(spdlog::level::debug);
    logger->set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] %v");
    spdlog::set_default_logger(logger);

    Circle3 c(5.0);
    Rectangle3 r(3.0, 4.0);

    c.info();
    r.info();

    Figure3* pc = &c;
    Figure3* pr = &r;

    spdlog::info("pc->area() = {:.4f}", pc->area());
    spdlog::info("pc->perimetr() = {:.4f}", pc->perimetr());
    pc->info();

    spdlog::info("pr->area() = {:.4f}", pr->area());
    spdlog::info("pr->perimetr() = {:.4f}", pr->perimetr());
    pr->info();

    std::vector<Figure3*> figures;
    figures.push_back(new Circle3(5.0));
    figures.push_back(new Rectangle3(3.0, 4.0));
    figures.push_back(new Circle3(2.0));

    for (Figure3* f : figures) {
        f->info();
    }

    for (Figure3* f : figures) {
        delete f;
    }

    return 0;
}

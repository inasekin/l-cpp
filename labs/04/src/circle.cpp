//
// Created by Иван Насекин on 23.03.2026.
//

#include "circle.h"
#include "spdlog/spdlog.h"

Circle::Circle(double r) : radius(r) {
    name = "Circle";
    spdlog::info("Circle constructor called, radius = {}", r);
}

Circle::~Circle() {
    spdlog::debug("Circle destructor called, radius = {}", radius);
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimetr() const {
    return 2.0 * M_PI * radius;
}

void Circle::info() const {
    spdlog::info("Circle::info() called -> radius={}, area={:.4f}, perimetr={:.4f}",
                 radius, area(), perimetr());
}

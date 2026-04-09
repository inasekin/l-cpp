//
// Created by Иван Насекин on 23.03.2026.
//

#include "rectangle.h"
#include "spdlog/spdlog.h"

Rectangle::Rectangle(double w, double h) : width(w), height(h) {
    name = "Rectangle";
    spdlog::info("Rectangle constructor called, width = {}, height = {}", w, h);
}

Rectangle::~Rectangle() {
    spdlog::debug("Rectangle destructor called, {}x{}", width, height);
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimetr() const {
    return 2.0 * (width + height);
}

void Rectangle::info() const {
    spdlog::info("Rectangle::info() called -> {}x{}, area={:.4f}, perimetr={:.4f}",
                 width, height, area(), perimetr());
}

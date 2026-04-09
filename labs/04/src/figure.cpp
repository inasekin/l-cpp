//
// Created by Иван Насекин on 23.03.2026.
//

#include "figure.h"
#include "spdlog/spdlog.h"

Figure::Figure() : name("Figure") {
    spdlog::info("Figure constructor called");
}

Figure::~Figure() {
    spdlog::debug("Figure destructor called");
}

double Figure::perimetr() const {
    spdlog::info("Figure::perimetr() base called");
    return 0.0;
}

void Figure::info() const {
    spdlog::info("Figure::info() called -> area={:.4f}, perimetr={:.4f}", area(), perimetr());
}

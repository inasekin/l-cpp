//
// Created by Иван Насекин on 23.03.2026.
//

#pragma once
#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle(double width, double height);
    ~Rectangle() override;

    double area() const override;
    double perimetr() const override;
    void info() const;

private:
    double width;
    double height;
};

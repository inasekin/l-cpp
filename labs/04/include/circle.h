//
// Created by Иван Насекин on 23.03.2026.
//

#pragma once
#include "figure.h"

class Circle : public Figure {
public:
    explicit Circle(double r);
    ~Circle() override;

    double area() const override;
    double perimetr() const override;
    void info() const;

private:
    double radius;
};
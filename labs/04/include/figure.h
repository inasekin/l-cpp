//
// Created by Иван Насекин on 23.03.2026.
//

#pragma once
#include <string>

class Figure {
public:
    Figure();
    virtual ~Figure();

    virtual double area() const = 0;
    virtual double perimetr() const;
    void info() const;

protected:
    std::string name;
};
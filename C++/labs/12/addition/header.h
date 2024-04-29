#pragma once

#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle();
    Rectangle(double l, double w);
    void setLength(double l);
    void setWidth(double w);
    double getLength() const;
    double getWidth() const;
    double perimeter() const;
    double area() const;
    void display() const;
    bool is_square() const;
    void draw() const;
};

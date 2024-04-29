#include "header.h"
#include <iostream>

Rectangle::Rectangle() : length(1.0), width(1.0) {}

Rectangle::Rectangle(double l, double w) {
    setLength(l);
    setWidth(w);
}

void Rectangle::setLength(double l) {
    if (l > 0 && l <= 20.0)
        length = l;
    else {
        std::cout << "Length must be at 0.0 to 20.0" << std::endl;
        length = 1.0;
    }
}

void Rectangle::setWidth(double w) {
    if (w > 0 && w <= 20.0)
        width = w;
    else {
        std::cout << "Width must be at 0.0 to 20.0" << std::endl;
        width = 1.0;
    }
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::perimeter() const {
    return 2 * (length + width);
}

double Rectangle::area() const {
    return length * width;
}

bool Rectangle::is_square() const{
    return length == width;
}

void Rectangle::display() const {
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Perimeter: " << perimeter() << std::endl;
    std::cout << "Area: " << area() << std::endl;
}

void Rectangle::draw() const{
    for (int i = 0; i < length; ++i) {
        std::cout << " _";
    }
    std::cout << std::endl;

    for (int i = 0; i < width; ++i) {
        std::cout << "|";
        for (int j = 0; j < length; ++j) {
            std::cout << "  ";
        }
        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < length; ++i) {
        std::cout << " -";
    }
    std::cout << std::endl;

}

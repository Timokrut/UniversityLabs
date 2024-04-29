#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() : length(1.0), width(1.0) {}

    Rectangle(double l, double w) {
        setLength(l);
        setWidth(w);
    }

    void setLength(double l) {
        if (l > 0 && l <= 20.0)
            length = l;
        else {
            std::cout << "Length must be at 0.0 to 20.0" << std::endl;
            length = 1.0;
        }
    }

    void setWidth(double w) {
        if (w > 0 && w <= 20.0)
            width = w;
        else {
            std::cout << "Width must be at 0.0 to 20.0" << std::endl;
            width = 1.0;
        }
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }

    double area() const {
        return length * width;
    }

    void display() const {
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Perimeter: " << perimeter() << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

int main() {

    double length;
    double width;

    std::cout << "Enter length of Rectangle: ";
    std::cin >> length;

    std::cout << "Enter width of Rectangle: ";
    std::cin >> width;

    Rectangle rect1(length, width);
    rect1.display();

    return 0;
}
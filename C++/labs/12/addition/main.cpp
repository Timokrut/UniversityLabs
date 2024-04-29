#include "header.h"
#include <iostream>

int main() {

    double length;
    double width;


    do {
        std::cout << "Enter length of Rectangle: ";
        std::cin >> length;
    }
    while (!(1 <= length and length <= 20));
    
    do {
        std::cout << "Enter width of Rectangle: ";
        std::cin >> width;
    }
    while (!(1 <= width and width <= 20));

    Rectangle rect1(length, width);

    rect1.display();

    rect1.draw();

    return 0;
}

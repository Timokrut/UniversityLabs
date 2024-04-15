#include <iostream>

class Rectangle {   
    private:
        double lenght;
        double width;
    public:
    Rectangle(double len, double wid): lenght(len), width(wid) {}

    int calculate_area(){
        return lenght * width;
    }
    int calculate_perimetr(){
        return (lenght + width) * 2;
    }
};

int main() 
{
    double length, width;
    std::cout << "Input the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Input the width of the rectangle: ";
    std::cin >> width; 

    Rectangle rectangle(length, width);

    double area = rectangle.calculate_area(); 
    std::cout << "\nArea: " << area << std::endl; 

    double perimeter = rectangle.calculate_perimetr(); 
    std::cout << "Perimeter: " << perimeter << std::endl; 

    return 0;
}

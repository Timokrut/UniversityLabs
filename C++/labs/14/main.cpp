#include "header.h"
#include <memory>
#include <ostream>
#include <stdexcept>
// № 4 
// Программа должна работать с фигурами 
// Rectangle (параметры: координаты левого верхнего угла, ширина и высота)
// Ellipse (параметры: координаты левого верхнего угла, два радиуса).


// Программа ``Графический редактор'' должна хранить схему в виде
// заданнозаданной в задании структуры данных, где хранятся 
// фигуры. Каждая фигура характеризуется уникальным идентификатором (int id), 
// координатами на экране (x, y), а также своими параметрами.

// Каждая фигура должна уметь выводить на экран свои параметры в  текстовом режиме с помощью метода print().

// Класс FigureList должен быть основан на связном списке. Связанный список
// должен быть реализован с помощью двух классов Node (элемент списка) и List (сам список). 


int main()
{
    FigureList list;
    list.addFigure(new Rectangle(1, 10, 20, 30, 40));
    list.addFigure(new Ellipse(2, 15, 25, 50, 25));

    // Print test
    std::cout << "Figures in the list:\n\n";
    list.printFigures();
    std::cout << std::endl;

    // Search tests
    Figure* foundFigure = list.findFigure(1);
    std::cout << "Searching for a figure with ID 1" << std::endl;
    foundFigure->print();

    std::cout << std::endl;
    
    try 
    {
    Figure* unfoundFigure = list.findFigure(3);
    std::cout << "Searching for a figure with ID 3" << std::endl;
    unfoundFigure->print();
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nDeleting figure with ID 1\n"; 
    list.erase(1);
    std::cout << "Figure with ID 1 succesfully deleted.\n";
    
    std::cout << "\nDeleting figure with ID 5\n"; 
    list.erase(5);
    std::cout << "Figure with ID 5 has not been deleted.\n\n";

    std::cout << "Figures in the list after deletion:\n";
    list.printFigures();

    return 0;
}

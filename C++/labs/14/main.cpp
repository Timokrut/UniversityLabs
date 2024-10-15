#include <csignal>
#include <iostream>
#include <ostream>

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


class Figure {
    public:
        int id;
        int x;
        int y;

    Figure(int id, int x, int y) : id(id), x(x), y(y) {}
    virtual ~Figure() = default;
    virtual void print() const = 0;
};

class Rectangle : public Figure {
    public:
        int width;
        int height;

    Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y), width(width), height(height) {}

    void print() const override 
    {
        std::cout << "Rectangle ID - " << id << std::endl;
        std::cout << "Top left corner coordinates: x - " << x << ", " << "y - " << y << std::endl;
        std::cout << "Width - " << width << std::endl;
        std::cout << "Height - " << height << std::endl;
    }
};

class Ellipse : public Figure {
    public:
        int radius_v;
        int radius_h;

    Ellipse(int id, int x, int y, int radius_w, int radius_h) : Figure(id, x, y), radius_v(radius_v), radius_h(radius_h) {}

    void print() const override
    {
        std::cout << "Ellipse ID - " << id << std::endl;
        std::cout << "Top left coordinates: x - " << x << ", " << "y - " << y << std::endl;
        std::cout << "Vertical radius - " << radius_v << std::endl;
        std::cout << "Horizontal radius - " << radius_h << std::endl;
    }
};

class Node{
    public:
        Figure* figure;
        Node* next;
        
    Node(Figure* figure) : next(nullptr), figure(figure) {}    
};

class FigureList{
    private:
        Node* head;
    
    public:
        FigureList() : head(nullptr) {}

        ~FigureList()
        {
            Node* current = head;
            while (current)
            {
                Node* next = current -> next;
                delete current->figure;
                delete current;
                current = next;
            }
        }

        void addFigure(Figure* fig)
        {
            Node* newNode = new Node(fig);
            
            if (!head)
                head = newNode;

            else 
            {
                Node* current = head;
                while (current->next)
                    current = current->next;
                
                current->next = newNode;
            }
        }


        Figure* findFigure(int id) const 
        {
            Node* current = head;
            while (current)
            {
                if (current->figure->id == id)
                    return current->figure;

                current = current -> next;
            }
            return nullptr;
        }
    
        void erase(int id) 
        {
            Node* current = head;
            Node* previous = nullptr;

            while (current)
            {
                if (current->figure->id == id)
                { 
                    if (previous)
                        previous->next = current->next;
                    else
                        head = current -> next;
                    delete current->figure;
                    delete current;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }

        void printFigures() const 
        {
            Node* current = head;
            while (current)
            {
                current->figure->print();
                current = current->next;
            }
        }
};

int main()
{
    FigureList list;
    list.addFigure(new Rectangle(1, 10, 20, 30, 40));
    list.addFigure(new Ellipse(2, 15, 25, 50, 25));

    std::cout << "Figures in the list:\n";
    list.printFigures();

    Figure* foundFigure = list.findFigure(1);
    if (foundFigure) 
    {
        std::cout << "Found figure with ID 1:\n";
        foundFigure->print();
    } 
    else
        std::cout << "Figure with ID 1 not found.\n";

    list.erase(1);
    std::cout << "Figure with ID 1 deleted.\n";
    
    std::cout << "Figures in the list after deletion:\n";
    list.printFigures();

    return 0;
}

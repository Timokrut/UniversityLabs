#include "header.h"

Figure::Figure(int id, int x, int y) : id(id), x(x), y(y) {}

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y), width(width), height(height) {}

void Rectangle::print() const 
{
    std::cout << "Rectangle ID - " << id << std::endl;
    std::cout << "Top left corner coordinates: x - " << x << ", " << "y - " << y << std::endl;
    std::cout << "Width - " << width << std::endl;
    std::cout << "Height - " << height << std::endl;
}

Ellipse::Ellipse(int id, int x, int y, int radius_v, int radius_h) : Figure(id, x, y), radius_v(radius_v), radius_h(radius_h) {}

void Ellipse::print() const 
{
    std::cout << "Ellipse ID - " << id << std::endl;
    std::cout << "Top left coordinates: x - " << x << ", " << "y - " << y << std::endl;
    std::cout << "Vertical radius - " << radius_v << std::endl;
    std::cout << "Horizontal radius - " << radius_h << std::endl;
}

Node::Node(Figure* figure) : next(nullptr), figure(figure) {}    

FigureList::FigureList() : head(nullptr) {}

FigureList::~FigureList()
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

void FigureList::addFigure(Figure* fig)
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


Figure* FigureList::findFigure(int id) const 
{
    Node* current = head;
    while (current)
    {
        if (current->figure->id == id)
            return current->figure;

        current = current -> next;
    }
    throw std::runtime_error("Wrong ID, Figure with your ID doesn't exist");
}
    
void FigureList::erase(int id) 
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

void FigureList::printFigures() const 
{
    Node* current = head;
    while (current)
    {
        current->figure->print();
        current = current->next;
    }
}

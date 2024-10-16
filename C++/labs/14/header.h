#include <iostream>

class Figure {
    public:
        int id;
        int x;
        int y;
    Figure(int id, int x, int y);
    virtual ~Figure() = default;
    virtual void print() const = 0;
};

class Rectangle : public Figure {
    public:
        int width;
        int height;
    Rectangle(int id, int x, int y, int width, int height);
    void print() const override; 
};

class Ellipse : public Figure {
    public:
        int radius_v;
        int radius_h;
    Ellipse(int id, int x, int y, int radius_v, int radius_h);
    void print() const override; 
};

class Node{
    public:
        Figure* figure;
        Node* next;
    Node(Figure* figure);
};

class FigureList{
    private:
        Node* head;
    public:
        FigureList();
        ~FigureList(); 
        void addFigure(Figure* fig); 
        Figure* findFigure(int id) const;
        void erase(int id); 
        void printFigures() const ; 
};

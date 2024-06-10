// Написать объявление через наследование figure (c координатой x y) rectangle (с x и y + ширина, высота)

class Figure
{
    protected:
        int x;
        int y;
};

class Rectangle : public Figure
{
    private:
        int width;
        int height;
};
// Написать пример где в классе есть private за место protected и программа выдаëт ошибку работы

class Figure
{
    private:
        int x;
        int y;
};

class Circle : Figure
{
    private:
        int radius;

    int x_plus_y_plus_radius()
    {
        return x + y + radius;
    }        
};
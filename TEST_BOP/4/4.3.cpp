// Перегрузите оператор << для класса, описывающего дату (число, месяц, год)
#include <iostream>

class Date
{
    private:
        int day;
        int month;
        size_t year;
    public:
    Date(): day(1), month(1), year(1970) {};

    friend std::ostream& operator<<(std::ostream &os, Date &date)
    {
        os << "Day: " << date.day << " Mohth: " << date.month << " Year: " << date.year;
        return os;
    }    
};

int main()
{
    Date date;
    std::cout << date;
}
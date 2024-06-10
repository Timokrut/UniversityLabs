// Объясните, что такое перегрузка функций на примере двух реализаций функции max.

#include <iostream>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

double max(double a, double b)
{
    return (a > b) ? a : b;
}

int main()
{
    int i_a = 2;
    int i_b = 5;

    double d_a = 2.1;
    double d_b = 5.6;

    std::cout << max(i_a, i_b) << std::endl;
    std::cout << max(d_a, d_b) << std::endl;
    return 0;
}
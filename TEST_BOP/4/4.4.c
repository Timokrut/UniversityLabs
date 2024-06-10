// Приведите реализацию функции swap для универсальной сортировки.
#include <stdio.h>

void swap(void* p1, void* p2, size_t size)
{
    char* pc1 = p1;
    char* pc2 = p2;

    int i = 0;
    char tmp;
    while (i < size)
    {
        tmp = *(pc1 + i);
        *(pc1 + i) = *(pc2 + i);
        *(pc2 + i) = tmp;
        i++;
    }
}


int main()
{
    double a, b;
    a = 2.569;
    b = 2.333;
    swap(&a, &b, sizeof(double));
    printf("%f %f", a, b);
    
}
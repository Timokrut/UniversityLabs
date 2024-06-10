// Написать алгоритм сравнения двух элементов в универсальной сортировке
int cmp_int(void* p1, void* p2)
{
    int* pi1 = p1;
    int* pi2 = p2;

    if (pi1 > pi2) return 1;
    if (pi1 == pi2) return 0;
    if (pi1 < pi2) return -1;
}
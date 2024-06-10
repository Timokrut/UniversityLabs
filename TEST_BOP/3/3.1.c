// Рассчитайте сложность O(n) для алгоритма
int f(int n)
{ 
    int k = 0; 

    while (n!=0) 
    { 
        n = n/2; 
        k++; 
    } 

    return k; 
}

// O(n) = log_2(n)


#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N <= 0)
    {
        printf("Enter a positive number\n");
        scanf("%d", &N);
    }

    int power = 0;
    int pre_last_power = 1;
    int last_power;
    while (1) {
        int next_power = pow(2, power);
        if (next_power >= N) {
            last_power = next_power;
            break;
        }
        pre_last_power = next_power;
        power++;
    }

    int temp1, temp2;
    temp1 = abs(N - pre_last_power);
    temp2 = abs(N - last_power);

    if (temp1 < temp2)
        printf("Ближайшая степень числа 2 к %d: %d\n", N, pre_last_power);
    else
        printf("Ближайшая степень числа 2 к %d: %d\n", N, last_power);
    
    return 0;
}
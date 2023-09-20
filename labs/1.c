#include "func.h"

// Ввести целое число N, вывести ближайшую к N степень числа 2.

int main() {
    // input a number
    int N;
    scanf("%d", &N);

    // cheking for positive
    while (N <= 0)
    {
        printf("Enter a positive number\n");
        scanf("%d", &N);
    }

    int power = 0;
    int pre_last_power = 1;
    int last_power;

    // finding 2 values (left and right to our)
    // ------8-----------15-16-----
    while (1) {
        int next_power = topow(2, power);
        if (next_power >= N) {
            last_power = next_power;
            break;
        }
        pre_last_power = next_power;
        power++;
    }

    // finding nearest
    int temp1, temp2;
    temp1 = abs(N - pre_last_power);
    temp2 = abs(N - last_power);

    if (temp1 < temp2)
        printf("Ближайшая степень числа 2 к %d: %d\n", N, pre_last_power);
    else
        printf("Ближайшая степень числа 2 к %d: %d\n", N, last_power);
    
    return 0;
}

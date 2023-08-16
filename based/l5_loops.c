#include <stdio.h>
#include <stdbool.h>

int main()
{
    // for loop

    for (int i = 0; i < 10; i+=2){
        printf("%d\n", i);
    }


    // indinity loop

    while (true)
    {
        printf("Паша лох <3\n");
    }
    

    // simple program that counts written digits

    int x = 0, y = 0, sum = 0;

    printf("Введите количество итераций\n");
    scanf("%d", &x);

    while (x != 0)
    {
        scanf("%d", &y);
        sum += y;
        x -= 1;
    }
    
    printf("%d",sum);

    // do while loop

    bool isfalse = false;
    do
    {
        printf("Yes\n");
    } while (isfalse);


    // breal / continue

    for (int x = 0; x < 10; x++)
    {
        if (x == 5)
            break;
        
        if (x % 2 == 0)
            continue;       
         
        printf("%d\n", x);
    }



    //E.G find max element in array

    int arr[] = {511, 67, 0, -20, -600};
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
        if (arr[i] < min)
        {
            min = arr[i];
        }

    }
    printf("MAX value: %d\n", max);
    printf("MIN value: %d\n", min);


    return 0;
}
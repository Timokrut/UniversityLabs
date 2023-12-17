// вводится строка и номер слова, которое должно перевернуться

#include <stdio.h>

int main() {

    // Ввод строки

    char data[100];
    printf("enter a string: ");

    int c;
    int index;
    while ((c = getchar()) != '\n' && index < 99)
    {
        data[index] = c;
        index ++;
    }
    data[index] = '\0';

    // получение индекса слова
    int idx; 
    printf("index of word would you like to reverse (from 0): ");
    scanf("%d", &idx);
    
    // ищем слово по индексу
    int counter = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < index + 1; i++)
    {
        if (data[i] == ' ' || data[i] == '\0')
        {   
            counter++;
            if (counter == idx)
                start = i + 1;
            if (counter - 1 == idx)
                {
                    end = i - 1;
                    break;
                }    
        }                
    }

    // выводим предложение на экран
    for (int i = 0; i < start; i++)
        printf("%c", data[i]);
    
    for (int i = end; i != start - 1; i--)
        printf("%c", data[i]);
    
    for (int i = end + 1; data[i] != '\0'; i++)
        printf("%c", data[i]);            
        

    return 0;
}
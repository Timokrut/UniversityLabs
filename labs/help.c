#include <stdio.h>

// Функция, которая проверяет, является ли строка палиндромом (симметричной)
int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];
    printf("Введите строку: ");

    int c;
    int index;
    while ((c = getchar()) != '\n' && index < 99)
    {
        str[index] = c;
        index ++;
    }
    str[index] = '\0';

    int start = 0;
    int end = 0;

    while (str[end] != '\0') {
        if (str[end] == ' ' || str[end + 1] == '\0') 
        {
            if (str[end] == ' ') 
                end--;

            if (isPalindrome(str, start, end)) 
            {
                for (int i = start; i <= end; i++)
                    printf("%c", str[i]);

                printf(" ");
            }
            end += 2;
            start = end;
        } 
        else 
            end++;
    }

    return 0;
}

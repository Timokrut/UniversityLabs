#include <stdio.h>
#include <string.h>

char *units[] = {"", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
char *teens[] = {"", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
char *tens[] = {"", "десять", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
char *hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};
char *thousands[] = {"", "одна тысяча", "две тысячи", "три тысячи", "четыре тысячи"};

void convertToWords(int num) 
{
    if (num < 10) {
        printf("%s", units[num]);
    } else if (num < 20) {
        printf("%s", teens[num - 10]);
    } else if (num < 100) {
        printf("%s ", tens[num / 10]);
        convertToWords(num % 10);
    } else if (num < 1000) {
        printf("%s ", hundreds[num / 100]);
        convertToWords(num % 100);
    } else if (num < 10000) {
        int thousandsDigit = num / 1000;
        if (thousandsDigit > 0 && thousandsDigit < 5) {
            printf("%s ", thousands[thousandsDigit]);
        } else {
            printf("%s %s ", units[thousandsDigit], thousands[4]);
        }
        convertToWords(num % 1000);
    }
}

int main() {
    int number;
    printf("Введите число от 1 до 9999: ");
    scanf("%d", &number);

    if (number < 1 || number > 9999) {
        printf("Число должно быть от 1 до 9999\n");
        return 1;
    }

    convertToWords(number);
    printf("\n");

    return 0;
}

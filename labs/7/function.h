#pragma once
char* decTo11th(long number, char result[])
{
    int i = 0;
    char current;

    if (number == 0) {
        result[0] = '0';
        result[1] = '\0'; 
        return result;
    }

    for (i = 0; number > 0; i++) {
        
        current = number % 11;

        if (current == 10)
            result[i] = 'A';
        else
            result[i] = current + 48;
        number /= 11;
    }

    result[i] = '\0';
    int j;
    for (j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}
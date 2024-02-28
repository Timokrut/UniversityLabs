void* bin(int number, int result[], int* length)
{
    int i = 0;

    char current;
    int len = 0;

    if (number == 0) {
        result[0] = 0;
        len = 1;
        
        *length = len;
        return result;
    }

    for (i = 0; number > 0; i++) {
        result[i] = number % 2;
        number /= 2;
        len++;
    }

    *length = len;
    return result;
}

int max(size_t num1, size_t num2)
{
    return (num1 < num2) ? num2 : num1;
}

int count_zeroes(int digits[], int* length)
{
    if (*length == 1)
        return *length - digits[0];
    else {
    int maxlen = 0;
    int curlen = 0;

    for (int i = 0; i < *length; i++)
    {
        if (digits[i] == 0) {
            curlen++;
            maxlen = max(curlen, maxlen);
        }
        else {
            curlen = 0;
        }
    }

    return maxlen;
    }
}
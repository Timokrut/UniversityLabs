#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEYS 100

typedef struct 
{
    const char *function;
    const char *header;
} FunctionHeaderMap;

typedef struct {
    char* keys[MAX_KEYS];
    int values[MAX_KEYS];
    int size;
} Dictionary;

void initDictionary(Dictionary *dict) {
    dict->size = 0;
}

void insert(Dictionary *dict, const char* key, int value) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->keys[i], key) == 0) {
            dict->values[i] += value;
            return;
        }
    }
    dict->keys[dict->size] = strdup(key);
    dict->values[dict->size] = value;
    dict->size++;
}

int getValue(Dictionary *dict, char* key) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->keys[i], key) == 0) {
            return dict->values[i];
        }
    }
    return 0; // Return 0 if key not found
}

const FunctionHeaderMap functionHeaderMap[] = {
    {"digittoint", "ctype.h"}, {"isalnum", "ctype.h"}, {"isalpha", "ctype.h"}, {"isascii", "ctype.h"}, {"isblank", "ctype.h"}, {"iscntrl", "ctype.h"}, {"isdigit", "ctype.h"}, {"isgraph", "ctype.h"}, {"islower", "ctype.h"}, {"isprint", "ctype.h"}, {"ispunct", "ctype.h"}, {"isspace", "ctype.h"}, {"isupper", "ctype.h"}, {"isxdigit", "ctype.h"}, {"toascii", "ctype.h"}, {"tolower", "ctype.h"}, {"toupper", "ctype.h"}, {"localeconv", "locale.h"}, {"setlocale", "locale.h"}, {" acos", "math.h"}, {" asin", "math.h"}, {" atan", "math.h"}, {" atan2", "math.h"}, {"atof", "stdlib.h"}, {" ceil", "math.h"}, {" cos", "math.h"}, {" cosh", "math.h"}, {" exp", "math.h"}, {" fabs", "math.h"}, {" floor", "math.h"}, {" fmod", "math.h"}, {" frexp", "math.h"}, {" ldexp", "math.h"}, {" log", "math.h"}, {" log10", "math.h"}, {" modf", "math.h"}, {" pow", "math.h"}, {" sin", "math.h"}, {" sinh", "math.h"}, {" sqrt", "math.h"}, {" tan", "math.h"}, {" tanh", "math.h"}, {"longjmp", "setjmp.h"}, {"setjmp", "setjmp.h"}, {"raise", "signal.h"}, {"offsetof", "stddef.h"}, {"clearerr", "stdio.h"}, {"fclose", "stdio.h"}, {"feof", "stdio.h"}, {"ferror", "stdio.h"}, {"fflush", "stdio.h"}, {"fgetc", "stdio.h"}, {"fgetpos", "stdio.h"}, {"fgets", "stdio.h"}, {"fopen", "stdio.h"}, {"freopen", "stdio.h"}, {"fdopen", "stdio.h"}, {"fprintf", "stdio.h"}, {"fputc", "stdio.h"}, {"fputs", "stdio.h"}, {"fread", "stdio.h"}, {"fscanf", "stdio.h"}, {"fseek", "stdio.h"}, {"fsetpos", "stdio.h"}, {"ftell", "stdio.h"}, {"fwrite", "stdio.h"}, {"getc", "stdio.h"}, {"getchar", "stdio.h"}, {"gets", "stdio.h"}, {"perror", "stdio.h"}, {"printf", "stdio.h"}, {"sprintf", "stdio.h"}, {"snprintf", "stdio.h"}, {"putc", "stdio.h"}, {"putchar", "stdio.h"}, {"fputchar", "stdio.h"}, {"puts", "stdio.h"}, {"remove", "stdio.h"}, {"rename", "stdio.h"}, {"rewind", "stdio.h"}, {"scanf", "stdio.h"}, {"sscanf", "stdio.h"}, {"setbuf", "stdio.h"}, {"setvbuf", "stdio.h"}, {"tmpfile", "stdio.h"}, {"tmpnam", "stdio.h"}, {"ungetc", "stdio.h"}, {"vprintf", "stdio.h"}, {"vfprintf", "stdio.h"}, {"vsprintf", "stdio.h"}, {"abort", "stdlib.h"}, {"abs", "stdlib.h"}, {"labs", "stdlib.h"}, {"atexit", "stdlib.h"}, {"atoi", "stdlib.h"}, {"atol", "stdlib.h"}, {"bsearch", "stdlib.h"}, {"calloc", "stdlib.h"}, {"div", "stdlib.h"}, {"ldiv", "stdlib.h"}, {"exit", "stdlib.h"}, {"free", "stdlib.h"}, {"itoa", "stdlib.h"}, {"getenv", "stdlib.h"}, {"ltoa", "stdlib.h"}, {"malloc", "stdlib.h"}, {"realloc", "stdlib.h"}, {"qsort", "stdlib.h"}, {"rand", "stdlib.h"}, {"srand", "stdlib.h"}, {"strtod", "stdlib.h"}, {"strtol", "stdlib.h"}, {"strtoul", "stdlib.h"}, {"system", "stdlib.h"}, {"memchr", "string.h"}, {"memcmp", "string.h"}, {"memcpy", "string.h"}, {"memmove", "string.h"}, {"memset", "string.h"}, {"strcat", "string.h"}, {"strncat", "string.h"}, {"strchr", "string.h"}, {"strcmp", "string.h"}, {"strncmp", "string.h"}, {"strcoll", "string.h"}, {"strcpy", "string.h"}, {"strncpy", "string.h"}, {"strcspn", "string.h"}, {"strerror", "string.h"}, {"strlen", "string.h"}, {"strpbrk", "string.h"}, {"strrchr", "string.h"}, {"strspn", "string.h"}, {"strstr", "string.h"}, {"strtok", "string.h"}, {"strxfrm", "string.h"}, {"asctime", "time.h"}, {"clock", "time.h"}, {"ctime", "time.h"}, {"difftime", "time.h"}, {"gmtime", "time.h"}, {"localtime", "time.h"}, {"mktime", "time.h"}, {"strftime", "time.h"}, {"time", "time.h"}, {"btowc", "wchar.h"}, {"fgetwc", "wchar.h"}, {"fgetws", "wchar.h"}, {"fputwc", "wchar.h"}, {"fputws", "wchar.h"}, {"fwide", "wchar.h"}, {"fwprintf", "wchar.h"}, {"fwscanf", "wchar.h"}, {"getwc", "wchar.h"}, {"getwchar", "wchar.h"}, {"mbrlen", "wchar.h"}, {"mbrtowc", "wchar.h"}, {"mbsinit", "wchar.h"}, {"mbsrtowcs", "wchar.h"}, {"putwc", "wchar.h"}, {"putwchar", "wchar.h"}, {"swprintf", "wchar.h"}, {"swscanf", "wchar.h"}, {"ungetwc", "wchar.h"}, {"vfwprintf", "wchar.h"}, {"vswprintf", "wchar.h"}, {"vwprintf", "wchar.h"}, {"wcrtomb", "wchar.h"}, {"wcscat", "wchar.h"}, {"wcschr", "wchar.h"}, {"wcscmp", "wchar.h"}, {"wcscoll", "wchar.h"}, {"wcscpy", "wchar.h"}, {"wcscspn", "wchar.h"}, {"wcsftime", "wchar.h"}, {"wcslen", "wchar.h"}, {"wcsncat", "wchar.h"}, {"wcsncmp", "wchar.h"}, {"wcsncpy", "wchar.h"}, {"wcspbrk", "wchar.h"}, {"wcsrchr", "wchar.h"}, {"wcsrtombs", "wchar.h"}, {"wcsspn", "wchar.h"}, {"wcsstr", "wchar.h"}, {"wcstod", "wchar.h"}, {"wcstok", "wchar.h"}, {"wcstol", "wchar.h"}, {"wcstoul", "wchar.h"}, {"wcsxfrm", "wchar.h"}, {"wctob", "wchar.h"}, {"wmemchr", "wchar.h"}, {"wmemcmp", "wchar.h"}, {"wmemcpy", "wchar.h"}, {"wmemmove", "wchar.h"}, {"wmemset", "wchar.h"}, {"wprintf", "wchar.h"}, {"wscanf", "wchar.h"}, {"iswalnum", "wctype.h"}, {"iswalpha", "wctype.h"}, {"iswcntrl", "wctype.h"}, {"iswctype", "wctype.h"}, {"iswdigit", "wctype.h"}, {"iswgraph", "wctype.h"}, {"iswlower", "wctype.h"}, {"iswprint", "wctype.h"}, {"iswpunct", "wctype.h"}, {"iswspace", "wctype.h"}, {"iswupper", "wctype.h"}, {"iswxdigit", "wctype.h"}, {"towctrans", "wctype.h"}, {"towlower", "wctype.h"}, {"towupper", "wctype.h"}, {"wctrans", "wctype.h"}, {"wctype", "wctype.h"}
};

void analyzeFile() 
{
    FILE* file = fopen("in.c", "r");
    FILE* out = fopen("out.h", "w");
    char line[MAX_LINE_LENGTH];

    Dictionary headers;
    initDictionary(&headers);

    insert(&headers,"ctype.h", 0); insert(&headers,"locale.h", 0); insert(&headers,"math.h", 0); insert(&headers,"setjmp.h", 0); insert(&headers,"signal.h", 0); insert(&headers,"stddef.h", 0); insert(&headers,"stdio.h", 0); insert(&headers,"stdlib.h", 0); insert(&headers,"string.h", 0); insert(&headers,"tgmath.h", 0); insert(&headers,"time.h", 0); insert(&headers,"wchar.h", 0); insert(&headers,"wctype.h", 0);


    while (fgets(line, sizeof(line), file)) {
        for (size_t i = 0; i < sizeof(functionHeaderMap) / sizeof(functionHeaderMap[0]); ++i) {
            if (strstr(line, functionHeaderMap[i].function) != NULL) {
                insert(&headers, functionHeaderMap[i].header, 1);
            }
        }
    }

    for (size_t i = 0; i < headers.size; ++i) {
        if (headers.values[i] > 0) {
            fprintf(out, "#include <%s>\n", headers.keys[i]);
        }
    }

    fclose(file);
    fclose(out);
}
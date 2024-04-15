#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для анализа файла и определения необходимых библиотек
void analyzeFile() {
    FILE* file = fopen("in.c", "r+");
    FILE* out = fopen("out.h", "w");

    char line[256];
    char line_answ[256];
    
   int flag_signal_h = 0;
    int flag_math_h = 0;
    int flag_wctype_h = 0;
    int flag_string_h = 0;
    int flag_stdlib_h = 0;
    int flag_setjmp_h = 0;
    int flag_wchar_h = 0;
    int flag_ctype_h = 0;
    int flag_locale_h = 0;
    int flag_stdio_h = 0;
    int flag_stddef_h = 0;
    int flag_time_h = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "digittoint") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isalnum") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isalpha") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isascii") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isblank") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "iscntrl") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isdigit") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isgraph") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "islower") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isprint") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "ispunct") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isspace") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isupper") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "isxdigit") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "toascii") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "tolower") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "toupper") && flag_ctype_h == 0) { fputs("#include <ctype.h>\n", out); flag_ctype_h = 1; }
        if (strstr(line, "localeconv") && flag_locale_h == 0) { fputs("#include <locale.h>\n", out); flag_locale_h = 1; }
        if (strstr(line, "setlocale") && flag_locale_h == 0) { fputs("#include <locale.h>\n", out); flag_locale_h = 1; }
        if (strstr(line, "acos") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1; }
        if (strstr(line, "asin") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1; }
        if (strstr(line, "atan") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1; }
        if (strstr(line, "atan2") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "atof") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1;}
        if (strstr(line, "ceil") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "cos") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "cosh") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "exp") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "fabs") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "floor") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "fmod") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "frexp") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "ldexp") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "log") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "log10") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "modf") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "pow") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "sin") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "sinh") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "sqrt") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "tan") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "tanh") && flag_math_h == 0) { fputs("#include <math.h>\n", out); flag_math_h = 1;}
        if (strstr(line, "longjmp") && flag_setjmp_h == 0) { fputs("#include <setjmp.h>\n", out); flag_setjmp_h = 1;}
        if (strstr(line, "setjmp") && flag_setjmp_h == 0) { fputs("#include <setjmp.h>\n", out); flag_setjmp_h = 1;}
        if (strstr(line, "raise") && flag_signal_h == 0) { fputs("#include <signal.h>\n", out); flag_signal_h = 1;}
        if (strstr(line, "offsetof") && flag_stddef_h == 0) { fputs("#include <stddef.h>\n", out); flag_stddef_h = 1;}
        if (strstr(line, "clearerr") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1;}
        if (strstr(line, "fclose") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1;}
        if (strstr(line, "feof") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1;}
        if (strstr(line, "ferror") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fflush") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fgetc") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fgetpos") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fgets") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fopen") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "freopen") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fdopen") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fputc") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fputs") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fread") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fscanf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fseek") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fsetpos") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "ftell") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fwrite") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "getc") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "getchar") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "gets") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "perror") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "printf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "sprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "snprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "putc") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "putchar") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "fputchar") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "puts") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "remove") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "rename") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "rewind") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "scanf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "sscanf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "setbuf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "setvbuf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "tmpfile") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "tmpnam") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "ungetc") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "vprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "vfprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "vsprintf") && flag_stdio_h == 0) { fputs("#include <stdio.h>\n", out); flag_stdio_h = 1; }
        if (strstr(line, "abort") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "abs") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "labs") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "atexit") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "atoi") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "atol") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "bsearch") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "calloc") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "div") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "ldiv") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "exit") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "free") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "itoa") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "getenv") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "ltoa") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "malloc") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "realloc") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "qsort") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "rand") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "srand") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "strtod") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "strtol") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "strtoul") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "system") && flag_stdlib_h == 0) { fputs("#include <stdlib.h>\n", out); flag_stdlib_h = 1; }
        if (strstr(line, "memchr") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "memcmp") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "memcpy") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "memmove") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "memset") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strcat") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strncat") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strchr") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strcmp") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strncmp") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strcoll") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strcpy") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strncpy") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strcspn") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strerror") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strlen") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strpbrk") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strrchr") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strspn") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strstr") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strtok") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "strxfrm") && flag_string_h == 0) { fputs("#include <string.h>\n", out); flag_string_h = 1; }
        if (strstr(line, "asctime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "clock") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "ctime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "difftime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "gmtime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "localtime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "mktime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "strftime") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "time") && flag_time_h == 0) { fputs("#include <time.h>\n", out); flag_time_h = 1; }
        if (strstr(line, "btowc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fgetwc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fgetws") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fputwc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fputws") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fwide") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fwprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "fwscanf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "getwc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "getwchar") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "mbrlen") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "mbrtowc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "mbsinit") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "mbsrtowcs") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "putwc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "putwchar") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "swprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "swscanf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "ungetwc") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "vfwprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "vswprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "vwprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcrtomb") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcscat") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcschr") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcscmp") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcscoll") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcscpy") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcscspn") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsftime") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcslen") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsncat") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsncmp") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsncpy") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcspbrk") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsrchr") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsrtombs") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsspn") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsstr") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcstod") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcstok") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcstol") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcstoul") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wcsxfrm") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wctob") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wmemchr") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wmemcmp") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wmemcpy") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wmemmove") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wmemset") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wprintf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "wscanf") && flag_wchar_h == 0) { fputs("#include <wchar.h>\n", out); flag_wchar_h = 1; }
        if (strstr(line, "iswalnum") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswalpha") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswcntrl") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswctype") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswdigit") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswgraph") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswlower") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswprint") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswpunct") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswspace") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswupper") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "iswxdigit") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "towctrans") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "towlower") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "towupper") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "wctrans") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }
        if (strstr(line, "wctype") && flag_wctype_h == 0) { fputs("#include <wctype.h>\n", out); flag_wctype_h = 1; }

    }
   fclose(file);
   fclose(out);
}

int main() {
    analyzeFile();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int custom_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void custom_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

char* replace_shortest_word(char* sentence, char* new_word) {
    int sentence_len = custom_strlen(sentence);
    char* copy = (char*)malloc((sentence_len + 1) * sizeof(char));
    if (copy == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    custom_strcpy(copy, sentence);

    char* shortest_word = copy;
    char* temp = NULL;

    while (*shortest_word != '\0') {
        while (*shortest_word == ' ' || *shortest_word == '\n') {
            shortest_word++;
        }

        if (*shortest_word == '\0') {
            break;
        }

        temp = shortest_word;
        while (*shortest_word != ' ' && *shortest_word != '\n' && *shortest_word != '\0') {
            shortest_word++;
        }

        if (temp != NULL && ((shortest_word - temp) < custom_strlen(new_word))) {
            int len_diff = custom_strlen(new_word) - (shortest_word - temp);
            int index = temp - copy;
            int new_sentence_len = sentence_len + len_diff;

            char* result = (char*)malloc((new_sentence_len + 1) * sizeof(char));
            if (result == NULL) {
                printf("Memory allocation failed.");
                free(copy);
                return NULL;
            }

            custom_strcpy(result, sentence);

            for (int i = index; i < sentence_len; i++) {
                result[i] = '\0';
            }

            for (int i = 0; i < custom_strlen(new_word); i++) {
                result[index + i] = new_word[i];
            }

            for (int i = index + custom_strlen(new_word), j = index + (shortest_word - temp); j <= sentence_len; i++, j++) {
                result[i] = sentence[j];
            }

            free(copy);
            return result;
        }
    }

    free(copy);
    return sentence;
}

int main() {
    char input_sentence[1000];
    char new_word[100];

    printf("Enter a sentence: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);
    input_sentence[custom_strlen(input_sentence) - 1] = '\0';

    printf("Input a word: ");
    scanf("%s", new_word);

    char* result = replace_shortest_word(input_sentence, new_word);
    if (result != NULL) {
        printf("Result: %s\n", result);
        free(result);
    }

    return 0;
}

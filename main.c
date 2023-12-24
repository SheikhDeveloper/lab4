#include <stdio.h>
//#include <readline/readline.h>
#include <stdlib.h>
//#include <string.h>
#include "lib/strings.h"
#include <time.h>

#define PROMPT "Введите строку: "

char change_case(char c);
void change_string_case(char **s);

int main() {
    double time_spent = 0.0;
    char *result;
    char *string = "NULL";
    char *tmp;
    while (string != NULL) {
        clock_t begin = clock();
        string = readline(PROMPT);
        if (string == NULL) break;
        char *word = strtok(string, "\t ");
        if (word == NULL) {
            printf("\"%s\"\n", string);
            free(string);
            continue;
        }
        result = strdup(word);
        int word_len = strlen(word);
        int current_len = word_len;
        word = strtok(NULL, "\t ");
        while (word != NULL) {
            word_len = strlen(word);
            current_len += word_len + 1;
            tmp = realloc(result, (current_len + 1) * sizeof(char));
            if (tmp == NULL) return 0;
            result = tmp;
            strcat(result, " ");
            strcat(result, word);
            word = strtok(NULL, "\t ");
        }
        change_string_case(&result);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n%f\n", time_spent);
        printf("\"%s\"\n", result);
        free(string);
        free(result);
    }
    return 0;
}

char change_case(char c) {
    if (c >= 'A' && c <= 'Z') return c + 'a' - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    return c;
}

void change_string_case(char **s) {
    if (s == NULL) return;
    char *tmp = *s;
    while (*tmp != 0) {
        *tmp = change_case(*tmp);
        tmp++;
    }
}

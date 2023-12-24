#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "strings.h"

size_t strlen(const char *s) {
    if (s == NULL) return 0;
    size_t result = 0;
    while (*s++ != 0) {
        result += 1;
    }
    return result;
}

char *strdup(const char *s) {
    if (s == NULL) return NULL;
    char *result = (char *)malloc((strlen(s) + 1) * sizeof(char));
    if (result == NULL) return result;
    char *tmp = result;
    while (*s != 0) {
        *tmp++ = *s++;
    }
    *tmp = 0;
    return result;
}

char *strcat(char *s1, const char *s2) {
    char *tmp = s1;
    while (*tmp != 0) tmp++;
    while (*s2 != 0) {
        *tmp++ = *s2++;
    }
    *tmp = 0;
    return s1;
}

char *readline(const char *prompt) {
    char *result = (char *)calloc(BUFFER_LENGTH, sizeof(char));
    if (result == NULL) return NULL;
    printf("%s", prompt);
    int scanned = scanf("%9[^\n]", result);
    if (scanned == EOF) {
        free(result);
        return NULL;
    }
    char *tmp;
    while (scanned == 1) {
        tmp = realloc(result, (strlen(result) + BUFFER_LENGTH) * sizeof(char));
        if (tmp == NULL) return NULL;
        result = tmp;
        while (*tmp != 0) tmp++;
        scanned = scanf("%9[^\n]", tmp);
    }
    tmp = realloc(result, (strlen(result) + 1) * sizeof(char));
    if (tmp == NULL) return NULL;
    result = tmp;
    scanf("%*c");
    return result;
} 

char *strtok(char *s, const char *separators) {
    static char *string;
    if (s == NULL) s = string;
    if (s == NULL) return NULL;
    char *tmp = s;
    while (*separators != 0) {
        while (*tmp != 0) {
            if (*tmp == *separators) {
                *tmp = 0;
                tmp++;
                if (*s == 0) {
                    s++;
                    continue;
                }
                string = tmp;
                return s;
            }
            tmp++;
        }
        tmp = s;
        separators++;
    }
    string = NULL;
    if (*s == 0) return NULL;
    return s;
}

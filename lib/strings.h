#ifndef STRINGS_H
#define STRINGS_H

#define BUFFER_LENGTH 10

size_t strlen(const char *s);
char *strdup(const char *s);
char *strcat(char *s1, const char *s2);
char *readline(const char *prompt);
char *strtok(char *s, const char *separators);

#endif

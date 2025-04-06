#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define INITIAL_SIZE 8

char **parse_input(char *input) {
    int size = INITIAL_SIZE;
    int index = 0;
    char **args = malloc(size * sizeof(char *));
    if (!args) {
        perror("malloc");
        return NULL;
    }

    char *token = strtok(input, " \t\r\n");
    while (token != NULL) {
        args[index++] = strdup(token);
        if (index >= size) {
            size *= 2;
            char **new_args = realloc(args, size * sizeof(char *));
            if (!new_args) {
                perror("realloc");
                free_args(args);
                return NULL;
            }
            args = new_args;
        }
        token = strtok(NULL, " \t\r\n");
    }

    args[index] = NULL;
    return args;
}

void free_args(char **args) {
    if (!args) return;
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "builtins.h"
#include "parser.h"

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("pico-shell> ");
        if (!fgets(input, sizeof(input), stdin)) {
            perror("fgets");
            break;
        }

        char **args = parse_input(input);
        if (!args || !args[0]) {
            free_args(args);
            continue;
        }

        if (handle_builtin(args)) {
            free_args(args);
            continue;
        }

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }

        free_args(args);
    }

    return 0;
}


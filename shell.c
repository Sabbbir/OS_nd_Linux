#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

void executeCommand(char** args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork() failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp() failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGS];
    char* token;

    while (1) {
        // Print prompt
        printf("Shell> ");

        // Read command
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("\n");
            break;
        }

        // Tokenize command
        int argCount = 0;
        token = strtok(command, " \n");
        while (token != NULL && argCount < MAX_ARGS - 1) {
            args[argCount++] = token;
            token = strtok(NULL, " \n");
        }
        args[argCount] = NULL;

        // Execute command
        executeCommand(args);
    }

    return 0;
}


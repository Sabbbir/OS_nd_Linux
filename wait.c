#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process executing...\n");
    } else if (pid > 0) {
        wait(NULL);
        printf("Child process terminated.\n");
    } else {
        printf("Fork failed\n");
    }
}

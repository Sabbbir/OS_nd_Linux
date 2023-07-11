#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
    } else if (pid > 0) {
        wait(NULL);
        printf("Child process completed\n");
    } else {
        printf("Fork failed\n");
    }
}
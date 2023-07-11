#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
pid_t pid = getpid();

printf("Process ID 1: %d\n", pid);
fork();
printf("Process ID 2: %d\n", getpid());
}


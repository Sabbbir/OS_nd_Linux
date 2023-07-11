#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"gcc", "--version", NULL};
    execvp(args[0], args);
    
    printf("This line will not be executed if execvp is successful.\n");
    
    return 0;
}

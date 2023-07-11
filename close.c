#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int file = open("/home/druglord/Documents/Varsity/3-1/OS_Lab_June/exec.c", O_WRONLY | O_APPEND);
    if (file == -1) {
        perror("open");
        return 1;
    }

    // Perform operations on the file

    close(file);
    return 0;
}


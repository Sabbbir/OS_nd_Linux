#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;

    // Open the file for writing (create if it doesn't exist)
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully!\n");

    // Close the file
    close(fd);

    return 0;
}


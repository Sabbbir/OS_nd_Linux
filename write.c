#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    ssize_t bytesWritten;
    char* message = "Hello, world!\n";

    // Open the file for writing (create if it doesn't exist)
    fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write the message to the file
    bytesWritten = write(fd, message, strlen(message));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    printf("Message written to file successfully!\n");

    // Close the file
    close(fd);

    return 0;
}


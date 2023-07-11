#include <stdio.h>
#include <dirent.h>

int main() {
    const char* directoryPath = "/home/druglord/Documents/Varsity/3-1/OS_Lab";
    DIR* directory = opendir(directoryPath);

    if (directory == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(directory);
}

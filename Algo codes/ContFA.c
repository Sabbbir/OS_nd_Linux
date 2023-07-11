#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 100

typedef struct {
    int starting_block;
    int length;
    char file_name[20];
} File;

void printFiles(File* files, int count) {
    printf("File Allocation Table:\n");
    printf("File Name\tStarting Block\tLength\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\t\t%d\n", files[i].file_name, files[i].starting_block, files[i].length);
    }
}

bool checkAvailability(File* files, int count, int start_block, int length) {
    for (int i = 0; i < count; i++) {
        int end_block = files[i].starting_block + files[i].length - 1;
        if ((start_block >= files[i].starting_block && start_block <= end_block) ||
            (end_block >= start_block && end_block <= start_block + length - 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    File files[MAX_BLOCKS];
    int file_count = 0;

    int total_blocks;
    printf("Enter the total number of blocks: ");
    scanf("%d", &total_blocks);

    int choice;
    while (true) {
        printf("\n1. Create a new file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        }

        printf("Enter the file name: ");
        scanf("%s", files[file_count].file_name);

        printf("Enter the starting block number: ");
        scanf("%d", &files[file_count].starting_block);

        printf("Enter the length of the file: ");
        scanf("%d", &files[file_count].length);

        if (!checkAvailability(files, file_count, files[file_count].starting_block, files[file_count].length)) {
            printf("File allocation failed. The blocks are not available.\n");
            continue;
        }

        file_count++;

        printf("File created successfully.\n");
    }

    printFiles(files, file_count);

    return 0;
}


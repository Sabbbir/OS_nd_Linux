#include <stdio.h>
#include <stdlib.h>

struct FileBlock {
    int blockNumber;
    struct FileBlock* next;
};

typedef struct FileBlock FileBlock;

FileBlock* createBlock(int blockNumber) {
    FileBlock* block = (FileBlock*)malloc(sizeof(FileBlock));
    block->blockNumber = blockNumber;
    block->next = NULL;
    return block;
}

void printFileAllocation(FileBlock* startBlock) {
    FileBlock* currentBlock = startBlock;
    while (currentBlock != NULL) {
        printf("%d -> ", currentBlock->blockNumber);
        currentBlock = currentBlock->next;
    }
    printf("NULL\n");
}

int main() {
    int totalBlocks;
    printf("Enter the total number of blocks in the disk: ");
    scanf("%d", &totalBlocks);

    FileBlock* startBlock = NULL;
    FileBlock* currentBlock = NULL;

    printf("Enter the block numbers allocated to the file (separated by spaces, -1 to end): ");
    int blockNumber;
    while (1) {
        scanf("%d", &blockNumber);
        if (blockNumber == -1) {
            break;
        }

        FileBlock* block = createBlock(blockNumber);

        if (startBlock == NULL) {
            startBlock = block;
            currentBlock = block;
        } else {
            currentBlock->next = block;
            currentBlock = block;
        }
    }

    printf("File Allocation: ");
    printFileAllocation(startBlock);

    return 0;
}


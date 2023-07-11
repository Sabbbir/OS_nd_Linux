#include <stdio.h>
#include <stdbool.h>

#define MAX_BLOCKS 100
#define MAX_INDEX_BLOCKS 10

typedef struct Node {
    int block_number;
    struct Node* next;
} Node;

typedef struct IndexNode {
    int index_block_number;
    Node* file_blocks;
    struct IndexNode* next;
} IndexNode;

void printFileBlocks(Node* head) {
    Node* current = head;
    printf("File Blocks: ");
    while (current != NULL) {
        printf("%d ", current->block_number);
        current = current->next;
    }
    printf("\n");
}

void printIndexedFiles(IndexNode* head) {
    IndexNode* current = head;
    while (current != NULL) {
        printf("Index Block Number: %d\n", current->index_block_number);
        printFileBlocks(current->file_blocks);
        current = current->next;
    }
}

int main() {
    IndexNode* indexed_files = NULL;
    int block_number;
    int index_block_count = 0;

    printf("Enter the file blocks (-1 to stop):\n");
    while (true) {
        scanf("%d", &block_number);
        if (block_number == -1)
            break;

        if (index_block_count == 0 || indexed_files == NULL || index_block_count >= MAX_INDEX_BLOCKS) {
            // Create a new index block
            IndexNode* new_index_block = (IndexNode*)malloc(sizeof(IndexNode));
            new_index_block->index_block_number = index_block_count;
            new_index_block->file_blocks = NULL;
            new_index_block->next = NULL;

            if (indexed_files == NULL) {
                indexed_files = new_index_block;
            } else {
                IndexNode* current = indexed_files;
                while (current->next != NULL)
                    current = current->next;
                current->next = new_index_block;
            }

            index_block_count++;
        }

        // Create a new file block
        Node* new_file_block = (Node*)malloc(sizeof(Node));
        new_file_block->block_number = block_number;
        new_file_block->next = NULL;

        // Add the file block to the last index block
        IndexNode* current_index_block = indexed_files;
        while (current_index_block->next != NULL)
            current_index_block = current_index_block->next;
        if (current_index_block->file_blocks == NULL) {
            current_index_block->file_blocks = new_file_block;
        } else {
            Node* current_file_block = current_index_block->file_blocks;
            while (current_file_block->next != NULL)
                current_file_block = current_file_block->next;
            current_file_block->next = new_file_block;
        }
    }

    printf("Indexed Files:\n");
    printIndexedFiles(indexed_files);

    return 0;
}


#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int reference_string[MAX_PAGES];
    int frames[MAX_FRAMES];
    int page_faults = 0;

    printf("Enter the reference string (page numbers separated by spaces):\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &reference_string[i]);
    }

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    int oldest_page_index = 0;

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = reference_string[i];
        int found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // If page is not found, replace the oldest page in a frame
        if (!found) {
            frames[oldest_page_index] = page;
            page_faults++;
            oldest_page_index = (oldest_page_index + 1) % MAX_FRAMES;
        }

        // Print current frame state
        printf("Page %d: [", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == -1)
                printf(" -");
            else
                printf(" %d", frames[j]);
        }
        printf(" ]\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}


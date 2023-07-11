#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int main() {
    int reference_string[MAX_PAGES];
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int counter[MAX_FRAMES] = {0};

    printf("Enter the reference string (page numbers separated by spaces):\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        scanf("%d", &reference_string[i]);
    }

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = reference_string[i];
        int found = 0;
        int empty_frame_index = -1;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                counter[j] = i;
                break;
            }

            // Check if the frame is empty
            if (frames[j] == -1 && empty_frame_index == -1) {
                empty_frame_index = j;
            }
        }

        // If page is not found, replace the least recently used page
        if (!found) {
            if (empty_frame_index != -1) {
                frames[empty_frame_index] = page;
                counter[empty_frame_index] = i;
            } else {
                int lru_frame_index = 0;
                for (int j = 1; j < MAX_FRAMES; j++) {
                    if (counter[j] < counter[lru_frame_index])
                        lru_frame_index = j;
                }

                frames[lru_frame_index] = page;
                counter[lru_frame_index] = i;
            }

            page_faults++;
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


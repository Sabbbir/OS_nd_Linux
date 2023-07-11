#include <stdio.h>
#include <stdbool.h>

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

    for (int i = 0; i < MAX_PAGES; i++) {
        int page = reference_string[i];
        bool found = false;
        bool empty_frame_found = false;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        // If page is not found, replace a page using the OPTIMAL algorithm
        if (!found) {
            // Check if there is an empty frame
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    empty_frame_found = true;
                    break;
                }
            }

            if (!empty_frame_found) {
                // Find the page that will not be used for the longest time
                int farthest_index = i;
                int replace_index = -1;
                for (int j = 0; j < MAX_FRAMES; j++) {
                    int k;
                    for (k = i + 1; k < MAX_PAGES; k++) {
                        if (reference_string[k] == frames[j]) {
                            break;
                        }
                    }
                    if (k > farthest_index) {
                        farthest_index = k;
                        replace_index = j;
                    }
                }

                // Replace the page with the farthest index
                frames[replace_index] = page;
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


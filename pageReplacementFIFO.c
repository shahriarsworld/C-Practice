#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3

bool inMem(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

void replacePage(int page, int frames[], int numFrames, int idx) {
    frames[idx] = page;
}

int main() {
    int numPages;
    printf("Enter number of pages: ");
    scanf("%d", &numPages);

    int refString[numPages];
    printf("Enter page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &refString[i]);
    }

    int frames[MAX_FRAMES] = {0};
    int faults = 0;

    for (int i = 0; i < numPages; i++) {
        int currPage = refString[i];
        if (!inMem(currPage, frames, MAX_FRAMES)) {
            replacePage(currPage, frames, MAX_FRAMES, faults % MAX_FRAMES);
            faults++;
        }
    }

    printf("Page faults using FIFO: %d\n", faults);
    return 0;
}

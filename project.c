#include <stdio.h>

// Function to calculate the number of page hits and page faults using the FIFO algorithm
void FIFO(int pages[], int n, int capacity) {
    int frame[capacity], page_hits = 0, page_faults = 0, frame_index = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                page_hits++;
                break;
            }
        }
        if (flag == 0) {
            frame[frame_index] = pages[i];
            frame_index = (frame_index + 1) % capacity;
            page_faults++;
        }
    }
    printf("Page hits using FIFO: %d\n", page_hits);
    printf("Page faults using FIFO: %d\n", page_faults);
}

// Function to calculate the number of page hits and page faults using the Optimal Page Replacement algorithm
void Optimal(int pages[], int n, int capacity) {
    int frame[capacity], page_hits = 0, page_faults = 0, frame_index = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                page_hits++;
                break;
            }
        }
        if (flag == 0) {
            int farthest = i;
            int replace = 0;
            for (int j = 0; j < capacity; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        break;
                    }
                }
                if (k == n) {
                    replace = j;
                    break;
                }
                if (k > farthest) {
                    farthest = k;
                    replace = j;
                }
            }
            frame[replace] = pages[i];
            page_faults++;
        }
    }
    printf("Page hits using Optimal: %d\n", page_hits);
    printf("Page faults using Optimal: %d\n", page_faults);
}

// Function to calculate the number of page hits and page faults using the LRU algorithm
void LRU(int pages[], int n, int capacity) {
    int frame[capacity], page_hits = 0, page_faults = 0, frame_index = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    int counter[capacity];
    for (int i = 0; i < capacity; i++) {
        counter[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                counter[j] = i;
                page_hits++;
                break;
            }
        }
        if (flag == 0) {
            int least_recently_used = 0;
            for (int j = 0; j < capacity; j++) {
                if (counter[j] < counter[least_recently_used]) {
                    least_recently_used = j;
                }
            }
            frame[least_recently_used] = pages[i];
            counter[least_recently_used] = i;
            page_faults++;
        }
    }
    printf("Page hits using LRU: %d\n", page_hits);
    printf("Page faults using LRU: %d\n", page_faults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the capacity of page frames: ");
    scanf("%d", &capacity);

    FIFO(pages, n, capacity);
    Optimal(pages, n, capacity);
    LRU(pages, n, capacity);

    return 0;
}

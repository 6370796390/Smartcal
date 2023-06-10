#include <stdio.h>

// Function to calculate the number of page faults using the FIFO algorithm
int FIFO(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frame[frame_pointer] = pages[i];
            frame_pointer = (frame_pointer + 1) % capacity;
            page_faults++;
        }
    }
    return page_faults;
}

// Function to calculate the number of page faults using the Optimal Page Replacement algorithm
int Optimal(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
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
    return page_faults;
}

// Function to calculate the number of page faults using the LRU algorithm
int LRU(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    int counter[capacity];
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                counter[j] = i;
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
    return page_faults;
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
    
    int fifo_faults = FIFO(pages, n, capacity);
    printf("Number of page faults using FIFO: %d\n", fifo_faults);
    
    int optimal_faults = Optimal(pages, n, capacity);
    printf("Number of page faults using Optimal: %d\n", optimal_faults);
    
    int lru_faults = LRU(pages, n, capacity);
    printf("Number of page faults using LRU: %d\n", lru_faults);
    
    return 0;
}
#include <stdio.h>

// Function to calculate the number of page faults using the FIFO algorithm
int FIFO(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frame[frame_pointer] = pages[i];
            frame_pointer = (frame_pointer + 1) % capacity;
            page_faults++;
        }
    }
    return page_faults;
}

// Function to calculate the number of page faults using the Optimal Page Replacement algorithm
int Optimal(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
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
    return page_faults;
}

// Function to calculate the number of page faults using the LRU algorithm
int LRU(int pages[], int n, int capacity) {
    int frame[capacity], page_faults = 0, frame_pointer = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    int counter[capacity];
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                counter[j] = i;
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
    return page_faults;
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
    
    int fifo_faults = FIFO(pages, n, capacity);
    printf("Number of page faults using FIFO: %d\n", fifo_faults);
    
    int optimal_faults = Optimal(pages, n, capacity);
    printf("Number of page faults using Optimal: %d\n", optimal_faults);
    
    int lru_faults = LRU(pages, n, capacity);
    printf("Number of page faults using LRU: %d\n", lru_faults);
    
    return 0;
}

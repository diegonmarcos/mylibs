#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a maximum number of allocations to track
#define MAX_ALLOCATIONS 1024

// Global array to store pointers (addresses) of allocated memory blocks
void *allocatedPointers[MAX_ALLOCATIONS] = {NULL};

// Function to add a new allocation to the tracking array
bool addAllocation(void *ptr) {
    for (int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (allocatedPointers[i] == NULL) {
            allocatedPointers[i] = ptr;
            return true; // Allocation added successfully
        }
    }
    return false; // Tracking array is full
}

// Function to remove an allocation from the tracking array
void removeAllocation(void *ptr) {
    for (int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (allocatedPointers[i] == ptr) {
            allocatedPointers[i] = NULL;
            return; // Allocation removed
        }
    }
}

// Function to check if an address is currently tracked as allocated
bool isAllocated(void *ptr) {
    for (int i = 0; i < MAX_ALLOCATIONS; i++) {
        if (allocatedPointers[i] == ptr) {
            return true; // Address is in the allocated list
        }
    }
    return false; // Address is not in the allocated list
}

// Wrapper for malloc that also tracks the allocation
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr) {
        if (!addAllocation(ptr)) {
            fprintf(stderr, "Error: Allocation tracking array is full!\n");
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}

// Wrapper for free that also removes the allocation from tracking
void my_free(void *ptr) {
    if (ptr) {
        removeAllocation(ptr);
    }
    free(ptr);
}

int main() {
    int *intPtr = (int *)my_malloc(sizeof(int) * 10);
    char *charPtr = (char *)my_malloc(sizeof(char) * 20);

    if (isAllocated(intPtr)) {
        printf("intPtr is allocated\n");
    }

    if (isAllocated(charPtr)) {
        printf("charPtr is allocated\n");
    }

    if (isAllocated(intPtr + 5)) {
        printf("intPtr + 5 is considered allocated (within the block)\n");
    }

    my_free(intPtr);

    if (!isAllocated(intPtr)) {
        printf("intPtr is now freed\n");
    }
    
    if (!isAllocated(intPtr + 5)) {
        printf("intPtr + 5 is considered freed\n");
    }

    my_free(charPtr);

    return 0;
}
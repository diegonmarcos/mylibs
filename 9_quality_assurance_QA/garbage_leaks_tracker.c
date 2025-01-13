#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOCATIONS 100

void *malloc_addresses[MAX_ALLOCATIONS] = {NULL}; // Initialize all to NULL

void allocate_memory(size_t size) 
{
  int i = 0;
  while (i < MAX_ALLOCATIONS && malloc_addresses[i] != NULL)
    i++;

  if (i < MAX_ALLOCATIONS) 
  {
    malloc_addresses[i] = malloc(size);
    if (malloc_addresses[i] == NULL) 
      printf("malloc failed!\n");
  	else
    printf("Too many allocations!\n");
  }
}

void free_all_memory(AllocationTracker *tracker) 
{
  for (int i = 0; i < tracker->num_allocations; i++)
    free(tracker->addresses[i]);
  tracker->num_allocations = 0;
}
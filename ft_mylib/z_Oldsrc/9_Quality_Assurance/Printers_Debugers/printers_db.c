#include <stdio.h>
#include <stdlib.h>


// Assuming a linked list structure like this
typedef struct Node {
    int data;
    struct Node *next;
} Node;


// ##############################################################################
// DEBBUGING PRINTERS & LOGGERS
// ##############################################################################
void print_linkedlist_debbuging(Node *head, int iterator) 
{
    FILE *output_file = fopen("debbuging.txt", "a"); // Open file in append mode

    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(output_file, "--------------------\n");
    fprintf(output_file, "Iteration: %d\n", iterator); 
    fprintf(output_file, "Linked List Values:\n");

    Node *current = head;
    while (current != NULL) {
        fprintf(output_file, "%d ", current->data);
        current = current->next;
    }
    fprintf(output_file, "\n");
    fprintf(output_file, "--------------------\n\n");

    fclose(output_file);
}

void print_array_debbugging(int *arr, int size, int iterator)
{
    FILE *output_file = fopen("debbuging.txt", "a"); // Open file in append mode=write at the end of the file

    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(output_file, "--------------------\n");
    fprintf(output_file, "Iteration: %d\n", iterator);
    fprintf(output_file, "Array:\n");

    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    fprintf(output_file, "\n");
    fprintf(output_file, "--------------------\n\n");

	fclose(output_file);
}


    
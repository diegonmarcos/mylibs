#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // For O_CREAT, O_RDWR, O_APPEND
#include <unistd.h> // For write, read, close

// Assuming you have custom versions of fprintf and atoi
// I'll use standard library versions for this example
#define ft_fprintf fprintf
#define ft_atoi atoi

// Function to allocate memory and record the pointer to a file
void	*ft_calloc_fd2(const char *filename, size_t count, size_t size)
{
    // Allocate memory using standard calloc
	void *ptr = calloc(count, size);
	if (ptr == NULL)
		write(1, "Alloc Error\n", 12);

    // Open the file in append mode (create if it doesn't exist)
    int fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
    if (fd == -1)
		write(1, "Alloc Error\n", 12);

    // Write the pointer address to the file
    // Using a formatted string for readability and ease of parsing later
    if (ft_fprintf(fd, "%p\n", ptr) < 0)
		write(1, "Alloc Error\n", 12);

    // Close the file
	close(fd);

	return ptr;
}

// Function to free all pointers recorded in the file
void	ft_free_fd2(const char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // No file or nothing allocated yet, just return
        if (errno == ENOENT)
			return ;
        write(1, "Alloc Error\n", 12);
    }

    char line[100]; // Buffer to read each line (adjust size as needed)
    void *ptr;

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL)
	{
        // Parse the pointer address from the line
        if (sscanf(line, "%p", &ptr) == 1) {
            // Free the memory
            free(ptr);
        }
    }

    // Close the file
    fclose(file);
    
    // Optional : Truncate the file to reuse it
    if (truncate(filename, 0) == -1)
		write(1, "Alloc Error\n", 12);
}
/*
int main()
{
    // Example usage
    int *numbers = (int *)ft_calloc_fd("allocations.txt", 10, sizeof(int));
    char *str = (char *)ft_calloc_fd("allocations.txt", 20, sizeof(char));

    // ... use the allocated memory ...
    strcpy(str, "Hello world!");
    for(int i = 0; i < 10; ++i)
	{
      numbers[i] = i;
    }
    printf("String: %s\n", str);
    printf("Numbers:");
    for (int i = 0; i < 10; i++)
	{
      printf(" %d", numbers[i]);
    }
    printf("\n");

    // Free all allocated memory
    ft_free_fd("allocations.txt");

    return 0;
	*/
}
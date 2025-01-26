/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector_bff.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:57:56 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/26 09:56:11 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_mylib.h"


#include "../../../include/ft_mylib.h"



void	*ft_calloc_fd(const char *filename, size_t count, size_t size)
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


/*
int	main()
{
//	t_list_garbage list_garbage = { .allocated_pointers = {NULL}, .blocks_count = 0 };
	t_list_garbage list_garbage;

	
	ft_struct_initializator(&list_garbage);
	// Allocate some memory using ft_malloc_gb
	int *intPtr = (int *)ft_malloc_gb(sizeof(int) * 10, &list_garbage);
	char *charPtr = (char *)ft_malloc_gb(sizeof(char) * 20, &list_garbage);
	double *dblPtr = (double *)ft_malloc_gb(sizeof(double) * 5, &list_garbage);

	// Check if the allocations were successful and tracked
	if (intPtr && charPtr && dblPtr)
	{
		printf("Memory allocated successfully!\n\n");

		// Check if the pointers are tracked
		if (is_allocated(intPtr, &list_garbage))
			printf("intPtr is allocated\n");
		if (is_allocated(charPtr, &list_garbage))
			printf("charPtr is allocated\n");
		if (is_allocated(dblPtr, &list_garbage))
			printf("dblPtr is allocated\n\n");

		// Free some memory using ft_free_gb
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(intPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(dblPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
//		ft_free_gb(charPtr, &list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
		ft_free_gb_all(&list_garbage);
		printf("Total Blocs Allocated is:%d\n", list_garbage.blocks_count);
		

	// Check if the pointers are no longer tracked
	if (!is_allocated(charPtr, &list_garbage))
		printf("charPtr is now freed\n");
	else
		printf("charPtr is still allocated\n");
	if (!is_allocated(intPtr, &list_garbage))
		printf("intPtr is now freed\n");
	else
		printf("intPtr is still allocated\n");
	if (!is_allocated(dblPtr, &list_garbage))
		printf("dblPtr is now freed\n");
	else
		printf("dblPtr is still allocated\n");
	}
	else
		printf("Memory allocation failed!\n");

	
	return 0;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:57:56 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/24 19:01:08 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
#include "../../../include/ft_mylib.h"

#define MAX_ALLOCATIONS 1024

typedef struct s_list_all {
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_all;
*/

// Function to add a new allocation to the tracking array
int	add_allocation(void *ptr, t_list_all *list_all)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (list_all->allocated_pointers[i] == NULL)
		{
			list_all->allocated_pointers[i] = ptr;
			list_all->blocks_count++;
			return (1);
		}
		i++;
	}
	return (0);
}

// Function to remove an allocation from the tracking array
void	remove_allocation(void *ptr, t_list_all *list_all)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (list_all->allocated_pointers[i] == ptr)
		{
			list_all->allocated_pointers[i] = NULL;
			list_all->blocks_count--;
			return ;
		}
		i++;
	}
}

// Function to check if an address is currently tracked as allocated
int	is_allocated(void *ptr, t_list_all *list_all)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (list_all->allocated_pointers[i] == ptr)
			return (1);
		i++;
	}
	return (0);
}

// Wrapper for malloc that also tracks the allocation
void	*ft_malloc_gb(size_t size, t_list_all *list_all)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
	{
		if (!add_allocation(ptr, list_all))
		{
			fprintf(stderr, "Error: Allocation tracking array is full!\n");
			free(ptr);
			return (NULL);
		}
	}
	return (ptr);
}

// Wrapper for free that also removes the allocation from tracking
void	ft_free_gb(void *ptr, t_list_all *list_all)
{
	if (ptr)
		remove_allocation(ptr, list_all);
	free(ptr);
}

// Function to free all allocated memory and reset block count
void	ft_free_gb_all(t_list_all *list_all)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		if (list_all->allocated_pointers[i] != NULL)
		{
			free(list_all->allocated_pointers[i]);
			list_all->allocated_pointers[i] = NULL;
			list_all->blocks_count = 0;
		}
		i++;
	}
}

void	ft_struct_initializator(t_list_all *my_list)
{
	int	i;

	i = 0;
	while (i < MAX_ALLOCATIONS)
	{
		my_list->allocated_pointers[i] = NULL;
		i++;
	}
	my_list->blocks_count = 0;
}
/*
int	main()
{
//	t_list_all my_list = { .allocated_pointers = {NULL}, .blocks_count = 0 };
	t_list_all my_list;
	
	ft_struct_initializator(&my_list); 										// Initialize the struct
	// Allocate some memory using ft_malloc_gb
	int *intPtr = (int *)ft_malloc_gb(sizeof(int) * 10, &my_list);
	char *charPtr = (char *)ft_malloc_gb(sizeof(char) * 20, &my_list);
	double *dblPtr = (double *)ft_malloc_gb(sizeof(double) * 5, &my_list);

	// Check if the allocations were successful and tracked
	if (intPtr && charPtr && dblPtr)
	{
		printf("Memory allocated successfully!\n\n");

		// Check if the pointers are tracked
		if (is_allocated(intPtr, &my_list))
			printf("intPtr is allocated\n");
		if (is_allocated(charPtr, &my_list))
			printf("charPtr is allocated\n");
		if (is_allocated(dblPtr, &my_list))
			printf("dblPtr is allocated\n\n");

		// Free some memory using ft_free_gb
		printf("Total Blocs Allocated is:%d\n", my_list.blocks_count);
//		ft_free_gb(intPtr, &my_list);
		printf("Total Blocs Allocated is:%d\n", my_list.blocks_count);
//		ft_free_gb(dblPtr, &my_list);
		printf("Total Blocs Allocated is:%d\n", my_list.blocks_count);
//		ft_free_gb(charPtr, &my_list);
		printf("Total Blocs Allocated is:%d\n", my_list.blocks_count);
		ft_free_gb_all(&my_list);
		printf("Total Blocs Allocated is:%d\n", my_list.blocks_count);
		

	// Check if the pointers are no longer tracked
	if (!is_allocated(charPtr, &my_list))
		printf("charPtr is now freed\n");
	else
		printf("charPtr is still allocated\n");
	if (!is_allocated(intPtr, &my_list))
		printf("intPtr is now freed\n");
	else
		printf("intPtr is still allocated\n");
	if (!is_allocated(dblPtr, &my_list))
		printf("dblPtr is now freed\n");
	else
		printf("dblPtr is still allocated\n");
	}
	else
		printf("Memory allocation failed!\n");

	
	return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage_collector_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:57:56 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/24 19:11:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_mylib.h"

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

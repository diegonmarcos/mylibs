/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_doubly2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:08:36 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/24 20:10:41 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Free the circular doubly linked list
*/
void	ft_free_list(t_list *stack)
{
	t_list	*current;
	t_list	*temp;

	if (stack == NULL)
		return ;
	current = stack->next;
	if (current != stack)
	{
		while (current != stack)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
	}
	free(stack);
}

/*
Find the minimum value node in a circular linked list 
	(excluding a given index)
*/
t_list	*find_min_node(t_list *stack)
{
	t_list	*min_node;
	t_list	*current;
	int		first_iteration;

	min_node = NULL;
	current = stack;
	first_iteration = 1;
	if (!stack)
		return (NULL);
	while (first_iteration || current != stack)
	{
		if (min_node == NULL || current->value < min_node->value)
		{
			min_node = current;
		}
		current = current->next;
		first_iteration = 0;
	}
	return (min_node);
}

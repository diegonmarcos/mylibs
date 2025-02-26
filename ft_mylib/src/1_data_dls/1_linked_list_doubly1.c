/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_doubly1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:08:36 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/03 17:16:34 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

/*
- Create a new node for the circular doubly linked list
*/

t_list_dls	*ft_lstnew(int value, int index)
{
	t_list_dls	*new_node;

	new_node = (t_list_dls *)ft_calloc_fd(NAME_M, 1, sizeof(t_list_dls));
	if (!new_node)
	{
		write(1, "Error\n", 6);
		halt_exit_(1);
	}
	new_node->value = value;
	new_node->index = index;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

/*
Add a node to the end of a circular doubly linked list
*/
void	ft_lstadd_back(t_list_dls **stack, t_list_dls *new_node)
{
	t_list_dls	*tail;

	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = tail;
		tail->next = new_node;
		(*stack)->prev = new_node;
	}
}

/*
Get the size of a circular doubly linked list
*/
int	ft_lstsize(t_list_dls *lst)
{
	int		i;
	t_list_dls	*current;

	if (!lst)
		return (0);
	i = 1;
	current = lst;
	while (current->next != lst)
	{
		i++;
		current = current->next;
	}
	return (i);
}

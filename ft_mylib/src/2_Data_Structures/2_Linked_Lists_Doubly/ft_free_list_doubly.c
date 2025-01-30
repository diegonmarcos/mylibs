/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_doubly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:16:05 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/30 19:34:40 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

/*
Free the circular doubly linked list
*/
void	ft_free_ls_doubly(t_list *stack)
{
	t_list	*current;
	t_list	*temp;
	int		switch_flag;

	if (stack == NULL)
		return ;
	switch_flag = 1;
	current = stack;
	while (current != stack || switch_flag)
	{
		temp = current;
		current = current->next;
		free(temp);
		switch_flag = 0;
	}
}

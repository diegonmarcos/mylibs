/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstadd_back_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:56:23 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:54 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void ft_lstadd_back(t_list_s **lst, t_list_s *new);
 * @brief: Adds the element ’new’ at the end of the list.
 * @param: #1. The address of a pointer to the first link of a list.
 * @return: None.
 * 
 * @note:
 * 
 * @file: ft_lstadd_back.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:49
 * ************************************************************************** *
 */

#include "ft_mylib.h"

void	ft_lstadd_back_s(t_list_s **lst, t_list_s *new)
{
	t_list_s	*tmp;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			tmp = ft_lstlast_s(*lst);
			tmp->next = new;
		}
	}
}

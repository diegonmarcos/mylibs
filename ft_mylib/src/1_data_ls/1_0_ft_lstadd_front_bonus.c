/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstadd_front_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:56:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void ft_lstadd_front(t_list_s **lst, t_list_s *new);
 * @brief: Adds the element ’new’ at the beginning of the list.
 * @param: #1. The address of a pointer to the first link of a list.
 * @return: None.
 * 
 * @note:
 * 
 * @file: ft_lstadd_front.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:50
 * ************************************************************************** *
 */

#include "ft_mylib.h"

void	ft_lstadd_front_s(t_list_s **lst, t_list_s *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

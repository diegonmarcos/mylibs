/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstsize_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:53 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: int ft_lstsize(t_list_s *lst);
 * @brief: Counts the number of elements in a list.
 * @param: #1. The beginning of the list.
 * @return: The length of the list.
 * 
 * @note:
 * 
 * @file: ft_lstsize.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:54
 * ************************************************************************** *
 */

#include "mylibc.h"

int	ft_lstsize_s(t_list_s *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

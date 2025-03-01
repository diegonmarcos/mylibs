/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstlast_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:26 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: t_list_s *ft_lstlast(t_list_s *lst);
 * @brief: Returns the last element of the list.
 * @param: #1. The beginning of the list.
 * @return: The last element of the list.
 * 
 * @note:
 * 
 * @file: ft_lstlast.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:52
 * ************************************************************************** *
 */

#include "mylibc.h"

t_list_s	*ft_lstlast_s(t_list_s *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

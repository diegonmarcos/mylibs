/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstiter_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:17 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void ft_lstiter(t_list_s *lst, void (*f)(void *));
 * @brief: Iterates the list 'lst' and applies the function 'f' to the 
 * 			content of each element.
 * @param: #1. The address of a pointer to an element.
 * @return: None.
 * 
 * @note:
 * 
 * @file: ft_lstiter.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:52
 * ************************************************************************** *
 */

#include "ft_mylib.h"

void	ft_lstiter_s(t_list_s *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

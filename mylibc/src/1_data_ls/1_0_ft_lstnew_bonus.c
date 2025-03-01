/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstnew_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:45 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 16:58:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: t_list_s *ft_lstnew(void *content);
 * @brief: Allocates (with malloc(3)) and returns a new element.
 * @param: #1. The content to create the new element with.
 * @return: The new element.
 * 
 * @note:
 * 
 * @file: ft_lstnew.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:53
 * ************************************************************************** *
 */

#include "mylibc.h"

t_list_s	*ft_lstnew_s(void *content)
{
	t_list_s	*new_lst;

	new_lst = (t_list_s *)malloc(sizeof(t_list_s));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	(*new_lst).next = NULL;
	return (new_lst);
}

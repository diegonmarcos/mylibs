/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_ft_lstmap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:57:37 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 17:00:46 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: t_list_s *ft_lstmap(t_list_s *lst, void *(*f)(void *), 
 * 				void (*del)(void *));
 * @brief: Iterates the list ’lst’ and applies the function ’f’ to the 
 * 			content of each element.
 * @param: #1. The address of a pointer to an element.
 * @return: The new list. NULL if the allocation fails.
 * 
 * @note:
 * 
 * @file: ft_lstmap.c
 * @author: Diego <dinepomu@student.42>
 * @created: 10/Nov/2024 08:57
 * @updated: 10/Nov/2024 11:53
 * ************************************************************************** *
 */

#include "mylibc.h"

t_list_s	*ft_lstmap_s(t_list_s *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list_s	*new_lst;
	t_list_s	*new_elem;
	void		*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew_s(content);
		if (!new_elem)
		{
			ft_lstclear_s(&new_lst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back_s(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

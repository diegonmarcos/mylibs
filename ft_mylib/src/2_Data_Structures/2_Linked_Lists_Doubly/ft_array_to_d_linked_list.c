/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_d_linked_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:43:52 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/03 17:15:42 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

t_list_dls	*array_to_d_linked_list(char **argv)
{
	t_list_dls	*tmp;
	int		i;
	t_list_dls	*stack ;

	stack = NULL;
	i = 0;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i]), -1);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}

t_list_dls	*array_int_to_d_linked_list(int *argv, int size)
{
	t_list_dls	*tmp;
	int		i;
	t_list_dls	*stack ;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		tmp = ft_lstnew(argv[i], -1);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}

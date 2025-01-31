/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:09:17 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/31 13:45:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function will free a array 2d
Will check if second array exist, if not will just free the header
*/

#include "ft_mylib.h"

void	ft_free(char **pointer)
{
	int	i;

	if (pointer == NULL)
		return ;
	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
	}
	free(pointer);
}

void	ft_free_array_2d(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

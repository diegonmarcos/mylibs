/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:09:17 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/25 17:11:13 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function will free a array 2d
Will check if second array exist, if not will just free the header
*/

#include <stdlib.h>

void	ft_free(char **pointer)
{
	int i;

	if (pointer == NULL)
		return;
	for (i = 0; pointer[i] != NULL; i++)
	{
		free(pointer[i]);
	}
	free(pointer);
}
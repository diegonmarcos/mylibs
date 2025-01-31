/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:55:20 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/31 20:17:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void *ft_calloc(size_t count, size_t size);
 * @brief: The calloc() function allocates memory for an array 
 * 			of nmemb elements
 * @param: count: The number of elements to allocate.
 * @return: The calloc() function returns a pointer to the allocated memory.
 * 
 * @note: 
 * 
 * @file: ft_calloc.c
 * @author: Diego <dinepomu@student.42>
 * @created: 03/Aug/2024 12:07
 * @updated: 10/Nov/2024 11:44
 * ************************************************************************** *
 */

#include "ft_mylib.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / count < size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, size * count);
	return (tmp);
}

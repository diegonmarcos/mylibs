/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:55:59 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/02 22:18:11 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: int ft_isdigit(int c);
 * @brief: checks for a digit (0 through 9).
 * @param: c: character to be checked.
 * @return: returns 1 if c is a digit, otherwise 0.
 * 
 * @note:
 * 
 * @file: ft_isdigit.c
 * @author: Diego <dinepomu@student.42>
 * @created: 03/Aug/2024 12:07
 * @updated: 10/Nov/2024 11:48
 * ************************************************************************** *
 */

#include "ft_mylib.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isnum(const char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_array_int(char *array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (ft_atoi((const char *)&array[i]) > INT_MAX
			|| ft_atoi((const char *)&array[i]) < INT_MIN)
			return (0);
	}
	return (1);
}
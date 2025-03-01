/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:09:02 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/22 12:50:14 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

int	ft_abs(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}
/* 
long	ft_sqrt(long number)
{
	long	i;

	i = 1;
	while (i * i < number)
		i++;
	return (i);
}

long	ft_pow(long number, long power)
{
	long	i;
	long	result;

	i = 0;
	result = 1;
	while (i < power)
	{
		result *= number;
		i++;
	}
	return (result);
}

long	ft_gcd(long a, long b)
{
	long	gcd;

	gcd = 1;
	while (gcd <= ft_min(a, b))
	{
		if (a % gcd == 0 && b % gcd == 0)
			gcd++;
	}
	return (gcd - 1);
} */


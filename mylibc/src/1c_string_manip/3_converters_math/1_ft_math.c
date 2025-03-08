/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:15:14 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/05 12:07:17 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

// *** digits_to_bits conversions *** //
int	digits_to_bits(int digits)
{
	int	bits;
	int	max_value;

	bits = 0;
	max_value = 1;
	if (digits <= 0)
		return (0);
	while (max_value < digits)
	{
		max_value *= 2;
		bits++;
	}
	return (bits);
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

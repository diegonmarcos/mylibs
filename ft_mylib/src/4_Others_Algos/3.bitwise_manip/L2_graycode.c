/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   L2_graycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:34:36 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/29 18:45:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

unsigned int	gray_code(unsigned int n)
{
	return (n ^ (n >> 1));
}

void	generate_gray_codes(unsigned int limit)
{
	unsigned int	i;

	i = 0;
	while (i <= limit)
	{
		print_bits(gray_code(i));
		printf("(#%d: %u)\n", i, gray_code(i));
		i++;
	}
}

/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		generate_gray_codes(atoi(argv[1]));
	return (0);
}
*/
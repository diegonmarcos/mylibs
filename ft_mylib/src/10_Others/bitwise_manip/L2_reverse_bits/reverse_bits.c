/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:40:05 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/31 20:19:39 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i--)
	{
		res = (res << 1) + (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}
/*
int	main(void)
{
	unsigned char	octet;

	octet = 8;
	print_bits(octet);
	printf("(%d)", octet);
	printf("\n");
	print_bits(reverse_bits(octet));
	printf("(%d)", reverse_bits(octet));
	return (0);
}*/
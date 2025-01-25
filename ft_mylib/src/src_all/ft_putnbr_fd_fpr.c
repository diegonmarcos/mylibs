/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_fpr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:56:17 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/26 00:00:32 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

static int	int_min(long fd, int n)
{
	(void)n;
	if (write(fd, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr_fd_fpr(long fd, int n)
{
	int	char_count;

	char_count = 0;
	if (n == -2147483648)
		return (int_min(fd, n));
	if (n < 0 && ++char_count)
	{
		if (write(fd, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		char_count += ft_putnbr(n / 10);
		if (char_count == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar(('0' + n)) == -1)
			return (-1);
		char_count++;
	}
	return (char_count);
}

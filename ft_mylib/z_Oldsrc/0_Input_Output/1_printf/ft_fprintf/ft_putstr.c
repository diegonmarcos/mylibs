/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:54:16 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/21 13:24:07 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(long fd, char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		if (write (fd, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (write(fd, &s[i], 1) != 1)
			return (-1);
		i++;
	}
	return (i);
}

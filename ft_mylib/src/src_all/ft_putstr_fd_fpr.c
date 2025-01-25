/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_fpr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:54:16 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/26 00:00:32 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int	ft_putstr_fd_fpr(long fd, char *s)
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

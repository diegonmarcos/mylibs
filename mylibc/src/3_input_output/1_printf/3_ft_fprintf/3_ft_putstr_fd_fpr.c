/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_fpr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:54:16 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/02/11 13:54:45 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

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

int	ft_putstrstr_fd_fpr(long fd, char **str)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (str[i])
	{
		len = ft_putstr_fd_fpr(fd, str[i]);
		write(fd, "\n", 1);
		if (len == -1)
			return (-1);
		count += len;
		i++;
	}
	return (count);
}

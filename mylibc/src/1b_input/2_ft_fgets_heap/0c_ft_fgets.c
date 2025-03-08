/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0c_get_next_line2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:12:14 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/03/06 16:12:17 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

int	ft_fgets(char **line, int fd)
{
	*line = get_next_line(fd);
	if (*line)
		return (1);
	return (0);
}
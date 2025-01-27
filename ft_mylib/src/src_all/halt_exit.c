/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halt_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:15:53 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/27 17:29:39 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

void	halt_exit1(int status)
{
	if (status == 1)
	{
		write(2, "Error\n", 6);
		exit(status);
	}
	exit(status);
}

/*
void	halt_exit_gb(int status)
{
	if (status == 1)
	{
		write(2, "Error\n", 6);
		ft_free_fd(NAME_M);
		exit(status);
	}
	ft_free_fd(NAME_M);
	exit(status);
}*/

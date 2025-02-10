/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:39:29 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/10 17:39:36 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

void	ft_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		halt_exit_fd(-1);
}

int	ft_fork()
{
	int pid;

	pid = fork();
	if (pid == -1)
		halt_exit_fd(1);
	return (pid);
}
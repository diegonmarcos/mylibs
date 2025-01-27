/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:58:40 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/27 20:27:35 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ************************************************************************** *
 * @syntax: void ft_putchar_fd(char c, int fd);
 * @brief: Outputs the character 'c' to the given file descriptor.
 * @param: 1. c : the character to output.
 * @return: none
 * 
 * @note:
 * 
 * @file: ft_putchar_fd.c
 * @author: Diego <dinepomu@student.42>
 * @created: 03/Aug/2024 12:07
 * @updated: 10/Nov/2024 11:56
 * ************************************************************************** *
 */

#include "ft_mylib.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

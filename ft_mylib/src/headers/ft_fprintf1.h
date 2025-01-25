/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:32:10 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/25 23:41:30 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

int			ft_putstr_fd_fpr(long fd, char *s);
static int	int_min(long fd, int n);
int			ft_putnbr_fd_fpr(long fd, int n);
int			ft_putchar_fd_fpr(long fd, int c);
static int	hexa_pointer_fd_fpr(char *base, unsigned long long n, int c);
static int	type_var(long fd, char formatSpecifier, va_list item);
static int	w_str_percent(long fd, char formatSpecifier, va_list item);
static int	w_str(long fd, const char *str, va_list item, int char_count);
int			ft_fprintf(char *filename, const char *str, ...);

#endif

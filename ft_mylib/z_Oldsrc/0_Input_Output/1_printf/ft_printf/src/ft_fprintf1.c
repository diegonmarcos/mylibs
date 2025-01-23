/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:21:23 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/22 15:24:53 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	ft_fprintf(char *filename, const char *str, ...)
{
	FILE *output_file;
	va_list args;
	int result;

	output_file = fopen(filename, "a");
	if (output_file == NULL)
	{
		return -1;
	}

	va_start(args, str);
	result = vfprintf(output_file, str, args);
	va_end(args);

	fclose(output_file);
	return result;
}

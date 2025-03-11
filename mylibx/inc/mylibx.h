/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:44:03 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/11 16:23:09 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef MYLIBX_H
# define MYLIBX_H

# include "mylibx_data.h"
# include <stdbool.h>
# include "../libs/minilibx_linux/mlx.h"

typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	bool	paint;
	float	polar[2];
}			t_point;

void	myputpixel(char *buffer, int endian, int color, int alpha);

void	copy_map(t_point *src, t_point *dst, int len);
void	matrix3_init(float (*matrix)[3]);
t_point	matrix3_multp(float matrix[3][3], t_point point);

#endif

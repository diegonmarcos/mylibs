/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1c_0_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:58:17 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/16 17:02:31 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

/*
 * ************************************************************************** *
 * @syntax: size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
 * @brief: Appends the NUL-terminated string src to the end of dst. It will 
 * 			append at most dstsize - strlen(dst) - 1 characters. It will 
 * 			then NUL-terminate
 * @param: 1. dst: The destination string
 * @return: The total length of the string they tried to create
 * 
 * @note:
 * 
 * @file: ft_strlcat.c
 * @author: Diego <dinepomu@student.42>
 * @created: 03/Aug/2024 12:07
 * @updated: 10/Nov/2024 12:00
 * ************************************************************************** *
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
	{
		return (dstsize + src_len);
	}
	if (src_len < dstsize - dst_len)
	{
		ft_memcpy(dst + dst_len, src, src_len +1);
	}
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}

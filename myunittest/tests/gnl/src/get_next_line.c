/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:12:14 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/03/26 07:39:48 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mylibc.h"

char	*get_next_line(int fd)
{
	t_gnl		g;
	char		buff[GNL_BUFFER_SIZE + 1] = {0};
	char		*line;
	static int	line_to_read;
	static char	**lines;

	ft_fprintf2("a", GNL_DBG, "#########\n # Hello MoF:\n######### \n%d\n", line_to_read);///
	if (!line_to_read)
	{
		copy_fd_to_array(fd, buff, &g);
		lines = (char **)ft_malloc((g.lines_count + 1) * sizeof(char *));
		ft_split_wc(&g, buff, lines);
	}
	if (!lines[line_to_read])
	{
		free_2d_array(lines);
		line_to_read = 0;
		return (NULL);
	}
	ft_fprintf1(GNL_DBG, "GNL_lines:\n\"%S\"\n", lines);///
	ft_fprintf1(GNL_DBG, "GNL_line:\n%sSize:%d", lines[line_to_read], ft_strlen_wc(lines[line_to_read], '\0'));///
	line = ft_strdup_(lines[line_to_read], ft_strlen_wc(lines[line_to_read], '\0') + 1);
	line_to_read++;
	ft_fprintf1(GNL_DBG, "\nGNL_line_out:\n%s\n\n\n", line);///
	return (line);
}

void	copy_fd_to_array(int fd, char *buff, t_gnl *g)
{
	g->lines_count = 0;
	g->char_count = 0;
	g->i = 0;
	while (ft_read(fd, &buff[g->i], 1))
	{
		if ((buff[0] && !g->i))
			g->lines_count++;
		else if (buff[g->i] && buff[g->i - 1] == '\n')
			g->lines_count++;
		g->i++;
//		ft_fprintf1(GNL_DBG, "\nCopy_fd_to_array:\n%s", &buff[g->i]);///
	}
	g->char_count = g->i;
	buff[g->i] = '\0';
	ft_fprintf1(GNL_DBG, "\nCopy_fd_to_array:\n\"%s\"", buff);///
	ft_fprintf1(GNL_DBG, "\nLines:%d\nChars:%d\n\n", g->lines_count, g->char_count);///
}

void	ft_split_wc(t_gnl *g, char *buff, char **lines)
{
	char	*line;
	int		line_length;
	char	*buff_p;

	g->i = 0;
	buff_p = buff;
	while (g->i < g->lines_count)
	{
		line_length = ft_strlen_wc(buff_p, '\n') + 1;
		line = ft_malloc(sizeof(char) * (line_length + 1));
		line = ft_memcpy_1(line, buff_p, line_length);
		lines[g->i] = line;
		ft_fprintf1(GNL_DBG, "\nSplit:\n\"%s\"\n", lines[g->i]);///
		g->i++;
		ft_fprintf1(GNL_DBG, "\nSPLIT_line_lenght:%d", line_length);///
		buff_p += line_length;
	}
	lines[g->lines_count] = NULL;
	ft_fprintf1(GNL_DBG, "\nSplit_F:\n\"%S\"\n", lines);///

}

int	ft_strlen_wc(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strdup_(char *s, int sizeofs)
{
	char	*dup;

	dup = (char *)ft_malloc(sizeof(char) * sizeofs + 1);
	return (ft_memcpy_1(dup, s, sizeofs));
}

char	*ft_memcpy_1(char *dst, const char *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == (void *)0 && src == NULL)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
	*(tmp_dst) = '\0';
	return (dst);
}

int	ft_read(int fd, char *buff, int size)
{
	int		ret;

	if (fd < 0)
		return (0);
	ret = read(fd, buff, size);
	if (ret == -1)
		exit (1);
	return (ret);
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (ptr);
}

void	free_2d_array(char **array)
{
	char	**tmp;

	tmp = array;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}

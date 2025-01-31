/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:12:14 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/31 20:17:15 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int	ft_read_to_left_str2(int fd, char **left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (1);
	rd_bytes = 1;
	while (!ft_strchr_gnl(*left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(*left_str);
			*left_str = NULL;
			return (1);
		}
		buff[rd_bytes] = '\0';
		*left_str = ft_strjoin_gnl(*left_str, buff, '\0');
	}
	free(buff);
	if (rd_bytes == 0)
		return (0);
	return (2);
}

int	get_next_line2(int fd, char **line)
{
	static char	*left_str;
	int			status;
	int			i;

	i = 0;
	while (1)
	{
		if (fd < 0 || BUFFER_SIZE <= 0 || !line)
			return (1);
		status = ft_read_to_left_str2(fd, &left_str);
		if (status == 1)
			return (1);
		if (status == 0 && (!left_str || !*left_str))
		{
			line[i] = NULL;
			return (0);
		}
		line[i] = ft_get_line(left_str);
		left_str = ft_new_left_str(left_str);
		i++;
	}
	return (2);
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test1.txt", O_RDONLY);
	fd3 = open("corrupted_file.txt", O_RDONLY);
	i = 1;
	printf("##############FRIST FILE\n");
	while ((line = get_next_line(fd1)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	i = 0;
	printf("\n##############SECOND FILE\n");
	while ((line = get_next_line(fd2)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	i = 0;
	printf("\n##############THIRD FILE\n");
	while ((line = get_next_line(fd3)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:30:07 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/23 09:51:52 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
//#  define BUFFER_SIZE 1
# endif

# define GNL_BUFFER_SIZE 1000000
//# define GNL_BUFFER_SIZE 1

# define GNL_DBG "gnl_debug.log"
# define GNL_OUT "gnl_output.log"

#include <stdlib.h>  // For system()
#include <fcntl.h>   // For open(), O_RDONLY, etc.
#include <unistd.h>  // For close()

typedef struct s_gnl
{
	char		*buff;
	int			char_count;
	int			lines_count;
	int			error;
	char		*ptr;
	int			i;
	int			j;
}				t_gnl;

// #########################################################
// MAIN
char	*get_next_line(int fd);

// #########################################################
// GNL


// LIBFT
void	copy_fd_to_array(int fd, char *buff, t_gnl *g);
void	ft_split_wc(t_gnl *g, char *buff, char **lines);
int		ft_strlen_wc(char *s, int c);
char	*ft_strdup_(char *s, int sizeofs);
char	*ft_memcpy_1(char *dst, const char *src, size_t n);
void	*ft_malloc(size_t size);
int		ft_read(int fd, char *buff, int size);
void	free_2d_array(char **array);

// #########################################################
// UTILS
/* size_t	ft_strlen_gnl(char *s, int c);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff, int c);
 */
// GNL
/* char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);
char	*ft_read_to_left_str(int fd, char *left_str);
 */
#endif




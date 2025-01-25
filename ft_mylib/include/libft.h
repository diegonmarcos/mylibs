/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:54 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/25 16:04:24 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// MACROS

// LIBRARIES
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

//##############################################################################
// 1. MEMORY MANAGEMENT
//##############################################################################


/* ************************************************************************** */
/* ************************************************************************** */
// ft_malloc
// ft_free
// ft_realloc
void	*ft_calloc(size_t count, size_t size);
void	halt_exit_(int status);

/* ************************************************************************** */
/* ************************************************************************** */
# ifndef MAX_ALLOCATIONS
#  define MAX_ALLOCATIONS 1024
# endif

typedef struct s_list_garbage
{
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_garbage;

void	ft_free_gb(void *ptr, t_list_garbage *list_garbage);
void	ft_free_gb_all(t_list_garbage *list_garbage);
void	ft_struct_initializator(t_list_garbage *my_list);
int		add_allocation(void *ptr, t_list_garbage *list_garbage);
void	remove_allocation(void *ptr, t_list_garbage *list_garbage);
void	remove_allocation(void *ptr, t_list_garbage *list_garbage);
int		is_allocated(void *ptr, t_list_garbage *list_garbage);
void	*ft_malloc_gb(size_t size, t_list_garbage *list_garbage);


/* ************************************************************************** */
/* ************************************************************************** */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);


//##############################################################################
// 2. STRING MANIPULATION
//##############################################################################

/* ************************************************************************** */
/* ************************************************************************** */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

/* ************************************************************************** */
/* ************************************************************************** */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);

/* ************************************************************************** */
/* ************************************************************************** */
// strcpy
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

/* ************************************************************************** */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* ************************************************************************** */
/* ************************************************************************** */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

//##############################################################################
// 3. STABDARD/STDERROR OUTPUT AND FILE DESCRIPTORS MANIP (IO)
//##############################################################################


/* ************************************************************************** */
/* ************************************************************************** */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/* ************************************************************************** */
/* ************************************************************************** */
// fopen
// fclose
// fread
// fwrite


//##############################################################################
// 4. ALGOS
//##############################################################################


/* ************************************************************************** */
/* ************************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));


//##############################################################################
// 4. DATA STRUCTURES
//##############################################################################


/* ************************************************************************** */
/* ************************************************************************** */
// DATA STRUCTURE FOR DOUBLY LS

typedef struct s_list		t_list;

struct s_list
{
	int		value;
	int		index;
	t_list	*next;
	t_list	*prev;
};

t_list	*ft_lstnew(int value, int index);
void	ft_lstadd_back(t_list **stack, t_list *new_node);
int		ft_lstsize(t_list *lst);
void	ft_free_list(t_list *stack);
t_list	*find_min_node(t_list *stack);
void	ft_swap_pointers(t_list **a, t_list **b);


/* ************************************************************************** */
/* ************************************************************************** */

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
*/

/* ************************************************************************** */
/* ************************************************************************** */

#endif

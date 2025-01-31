/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:54 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/31 20:37:22 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIB_H
# define FT_MYLIB_H
// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//

/*#########################################################################	*/
/* 0.0 MACROS																*/
/*#########################################################################	*/
// GET NEXT LINE2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// GARBAGE COLLECTOR
# ifndef MAX_ALLOCATIONS
#  define MAX_ALLOCATIONS 102400
# endif

// Unsigned Int
# ifndef SIZE_MAX
#  define SIZE_MAX INT_MAX
# endif

# ifndef NAME_M
#  define NAME_M "log/5.bff/malloc_allocs.txt"
# endif

/*#########################################################################	*/
/* 0.1 LIBRARIES															*/
/*#########################################################################	*/
# include <unistd.h>	// open, close, read, write, fork(), exec(), pipe()
# include <fcntl.h>		// file control O_RDONLY, O_RDWR, O_APPEND, O_TRUNC
# include <stdarg.h> 	// Variadic functions for fprintf and printf
# include <stdlib.h>	// realloc,free|atoi,strtol|rand|exit|search/sort
# include <stdio.h> 	// High Level I/O(frwrite,fread/fprintf) and erros
# include <string.h>	// Actually can't use, only for testers...
# include <stddef.h> 	// Defs of NULL, size_t(unsign int)
# include <limits.h>	// Defs of INT_MAX, SIZE_MAX(size_t/uInt), LONG_MAX

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//

/*#########################################################################	*/
/* 1. MEMORY MANAGEMENT														*/
/*#########################################################################	*/

/* ***************************************************************** */
/* ***************************************************************** */
void	print_bits(unsigned char octet);
/* ***************************************************************** */
/* ***************************************************************** */
void	*ft_calloc(size_t count, size_t size);
void	halt_exit_(int status);
void	halt_exit1(int status);
void	halt_exit(int status, char *description);

/* ***************************************************************** */
/* ***************************************************************** */
void	*ft_calloc_fd(char *filename, size_t count, size_t sizeofvar);
void	ft_free_fd(char *filename);
void	ft_free_array_2d(char **array);
void	ft_free_fd_new(char *filename);

/* ***************************************************************** */
/* ***************************************************************** */
typedef struct s_list_garbage
{
	void	*allocated_pointers[MAX_ALLOCATIONS];
	int		blocks_count;
}			t_list_garbage;

void	ft_initializator_list_gargabe(t_list_garbage *my_list);
void	*ft_malloc_gb(size_t size, t_list_garbage *list_garbage);
int		add_allocation(void *ptr, t_list_garbage *list_garbage);
int		is_allocated(void *ptr, t_list_garbage *list_garbage);
void	remove_allocation(void *ptr, t_list_garbage *list_garbage);
void	ft_free_gb(void *ptr, t_list_garbage *list_garbage);
void	ft_free_gb_all(t_list_garbage *list_garbage);

/* ***************************************************************** */
/* ***************************************************************** */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*#########################################################################	*/
/* 2. STRING MANIPULATION 													*/
/*#########################################################################	*/

/* ***************************************************************** */
/* ***************************************************************** */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

/* ***************************************************************** */
/* ***************************************************************** */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *filename, char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char *filename, char const *s, unsigned int start,
			size_t len);
char	**ft_split(char *filename, const char *s, char c);
int		ft_contains(int num, char **argv, int i);

/* ***************************************************************** */
/* ***************************************************************** */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(char *name, const char *s1);

/* ***************************************************************** */
/* ***************************************************************** */
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* ***************************************************************** */
/* ***************************************************************** */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnum(char *num);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
void	*ft_atoi_base(const char *str, int str_base);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*#########################################################################	*/
/* 3. STANDARDT/STDERROR OUTPUT AND FILE DESCRIPTORS MANIP (IO)				*/
/*#########################################################################	*/

/* ***************************************************************** */
/* ***************************************************************** */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putnbr(int n);

/* ***************************************************************** */
/* ***************************************************************** */
//FT_FPRINTF
int		ft_fprintf1(char *filename, const char *str, ...);

//
int		ft_putstr_fd_fpr(long fd, char *s);
int		ft_putnbr_fd_fpr(long fd, int n);
int		ft_putchar_fd_fpr(long fd, int c);
int		ft_putchar(char c);
int		ft_putchar_int(int c);
int		ft_putstr(char *str);
int		ft_pointer_hexa_fpr(long fd, void *p);

/* ***************************************************************** */
/* ***************************************************************** */
//FT_PRINTF
int		ft_printf(const	char *str, ...);
size_t	ft_num_unsign(size_t num);
int		ft_pointer_hexa(void *p);
int		ft_hexa_minusc(int num);
int		ft_hexa_mayusc(int num);

/* ***************************************************************** */
/* ***************************************************************** */
//GET_NEXT_LINE2
int		get_next_line2(int fd, char **line);
//
size_t	ft_strlen_gnl(char *s, int c);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff, int c);
int		ft_read_to_left_str2(int fd, char **left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);

/* ***************************************************************** */
/* ***************************************************************** */
//GET_NEXT_LINE
char	*get_next_line(int fd);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);

/* ***************************************************************** */
/* ***************************************************************** */
// FGETS(gnl) | FGETS2(gnl2) | FSCANF(ft_split)
int		ft_fgets(char **line, int fd);
void	ft_scanf(char *filename, char *line, void **pointers,
			int *num_pointers);

/*#########################################################################	*/
/* 4. ALGOS																	*/
/*#########################################################################	*/

/* ***************************************************************** */
/* ***************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ***************************************************************** */
/* ***************************************************************** */
void	heapify(int arr[], int n, int i);
void	heap_sort(int arr[], int n);
void	quick_sort(int arr[], int low, int high, int depthlimit);
int		ft_log_introsort(int n);
void	intro_sort(int arr[], int n);
void	swap_introsort(int *a, int *b);
int		partition(int arr[], int low, int high);
void	heapify(int arr[], int n, int i);

/*#########################################################################	*/
/* 5. DATA STRUCTURES														*/
/*#########################################################################	*/

/* ***************************************************************** */
/* ***************************************************************** */
// DATA STRUCTURE FOR HASHTABLE/MAP/DIC

typedef struct s_node_
{
	char			*key;
	int				value;
	struct s_node_	*next;
}				t_node_;

void	insert(t_node_ **table, int size, const char *key, int value);
int		get(t_node_ **table, int size, const char *key);
void	free_hashtable(t_node_ **table, int size);
size_t	hash(char *key, int size);
t_node_	*create_node(char *key, int value);

/* ***************************************************************** */
/* ***************************************************************** */

// DATA STRUCTURE FOR SINGLY LINEKD LIST

typedef struct s_list_s
{
	void				*content;
	struct s_list_s		*next;
}					t_list_s;

void	ft_free_ls_simple(t_list_s *stack);
/*
t_list_s	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list_s **lst, t_list *new);
int		ft_lstsize(t_list_s *lst);
t_list_s	*ft_lstlast(t_list_s *lst);
void	ft_lstadd_back(t_list_s **lst, t_list *new);
void	ft_lstdelone(t_list_s *lst, void (*del)(void*));
void	ft_lstclear(t_list_s **lst, void (*del)(void*));
void	ft_lstiter(t_list_s *lst, void (*f)(void*));
t_list_s	*ft_lstmap(t_list_s *lst, void *(*f)(void*), void (*del)(void*));
*/

/* ***************************************************************** */
/* ***************************************************************** */
// DATA STRUCTURE FOR DOUBLY LINKED LIST

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list	*ft_lstnew(int value, int index);
void	ft_lstadd_back(t_list **stack, t_list *new_node);
int		ft_lstsize(t_list *lst);
t_list	*find_min_node(t_list *stack);
void	ft_swap_pointers(t_list **a, t_list **b);
t_list	*array_to_d_linked_list(char **argv);
void	ft_print_ls_doubly(t_list *stack);
void	ft_free_ls_doubly(t_list *stack);

/* ***************************************************************** */
/* ***************************************************************** */
// FOR THE PRINTERS DEBUGGERS
/*
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;
*/

#endif

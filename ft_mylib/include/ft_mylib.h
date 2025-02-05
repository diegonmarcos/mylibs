/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:47:54 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/02/05 15:49:08 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MYLIB_H
# define FT_MYLIB_H
// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#####################################################################	*/
/* 0.0 MACROS															*/
/*#####################################################################	*/
// GET NEXT LINE2
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

// Unsigned Int
# ifndef SIZE_MAX
#  define SIZE_MAX INT_MAX
# endif

# ifndef NAME_M
#  define NAME_M "log/2.Memory_Check/allocs/malloc_allocs.txt"
# endif

/*#####################################################################	*/
/* 0.1 LIBRARIES														*/
/*#####################################################################	*/
# include <unistd.h>	// open, close, read, write, fork(), exec(), pipe()
# include <fcntl.h>		// file control O_RDONLY, O_RDWR, O_APPEND, O_TRUNC
# include <stdarg.h> 	// Variadic functions for fprintf and printf
# include <stdlib.h>	// realloc,free|atoi,strtol|rand|exit|search/sort
# include <stdio.h> 	// High Level I/O(frwrite,fread/fprintf) and erros
# include <string.h>	// Actually can't use, only for testers...
# include <stddef.h> 	// Defs of NULL, size_t(unsign int)
# include <limits.h>	// Defs of INT_MAX, SIZE_MAX(size_t/uInt), LONG_MAX
# include "ft_mylib_data.h" //*ft_initializator_list_gargabe(void);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//

/* ***************************************************************** */
/* 1. STRING MANIPULATION low leve									 */
/* ***************************************************************** */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*#########################################################################	*/
/* 2. STRING MANIPULATION high level										*/
/*#########################################################################	*/

/* ************************************************************* */
/* ************************************************************* */
size_t	ft_strlen(const char *str);
int		ft_countwords(char const *s, char c);
int		ft_array_size(char **s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(char *name, const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp_duplicate(char *str, char **array);
int		ft_strcmp_duplicate_inter(char **array);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *filename, char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char *filename, char const *s, unsigned int start,
			size_t len);
char	**ft_split(char *filename, const char *s, char c);
long	*ft_split_long(char *filename, char const *array_source,
			char delimitator, int *size);
int		ft_contains(int num, char **argv, int i);

/* ************************************************************* */
/* ************************************************************* */
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_strchr_char_duplicate(char c, char **argv, int i);
char	*ft_strchr_char_duplicate_interation(char **array_char);
int		*ft_strchr_int_duplicate(int *array_int, int size, int position);
int		*ft_strchr_int_duplicate_interation(int *array_int, int size);

/* ************************************************************* */
/* SRING MANIPULATION / CONVERTERS AND CHECKERS					 */
/* ************************************************************* */
int		ft_atoi(const char *str);
long	ft_atoi_long(const char *ptr);
void	*ft_atoi_base(const char *str, int str_base);
int		ft_atoi_safe(const char *ptr);
long	*ft_atoi_long_array(const char **ptr);
char	*ft_itoa(int n);
size_t	ft_num_unsign(size_t num);
int		ft_pointer_hexa(void *p);
int		ft_hexa_minusc(int num);
int		ft_hexa_mayusc(int num);

/* ************************************************************* */
/* ************************************************************* */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnum(const char *num);
int		ft_is_num_num(const char **str);
int		ft_isprint(int c);
int		ft_is_array_int(char **array);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_is_sorted_array_char(char **arr);
int		ft_is_sorted_array_int(int	*arr, int size);

/* ************************************************************* */
/* STRING MANIP / HALTERS										 */
/* ************************************************************* */
void	halt_exit_(int status);
void	halt_exit1(int status);
void	halt_exit(int status, char *description);

/*#########################################################################	*/
/* 3. STANDARDT/STDERROR OUTPUT AND FILE DESCRIPTORS MANIP (IO)				*/
/*#########################################################################	*/

/* ************************************************************* */
/* PRINTERS low level											 */
/* ************************************************************* */
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr(char *str);
int		ft_putstr_str(char **str);
int		ft_putnbr(int n);
int		ft_putnbr_nbr(int *n, int size);
int		ft_putstr_fd_fpr(long fd, char *s);
int		ft_putnbr_fd_fpr(long fd, int n);
int		ft_putchar_fd_fpr(long fd, int c);
int		ft_putchar(char c);
int		ft_putchar_int(int c);
int		ft_pointer_hexa_fpr(long fd, void *p);

/* ************************************************************* */
/* PRINTERS high level											 */
/* ************************************************************* */
int		ft_fprintf(char *filename, const char *str, ...);
int		ft_fprintf1(char *filename, const char *str, ...);
int		ft_printf(const	char *str, ...);

/* ************************************************************* */
/* ************************************************************* */
char	*get_next_line(int fd);
int		get_next_line2(int fd, char **line);
// FGETS(gnl) | FGETS2(gnl2) | FSCANF(ft_split)
int		ft_fgets(char **line, int fd);
void	ft_scanf(char *filename, char *line, void **pointers,
			int *num_pointers);

/*#########################################################################	*/
/* 4. ALGOS																	*/
/*#########################################################################	*/

/* ************************************************************* */
/* ************************************************************* */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	print_bits(unsigned char octet);

/* ************************************************************* */
/* ALGOS/SORTING 												 */
/* ************************************************************* */
void	heapify(int arr[], int n, int i);
void	heap_sort(int arr[], int n);
void	quick_sort(int arr[], int low, int high, int depthlimit);
int		ft_log_introsort(int n);
void	intro_sort(int arr[], int n);
void	swap_introsort(int *a, int *b);
int		partition(int arr[], int low, int high);
void	heapify(int arr[], int n, int i);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//
/*#########################################################################	*/
/* 5. DATA STRUCTURES & MEMORY MANAGEMENT									*/
/*#########################################################################	*/

/* ************************************************************* */
/* DATA STRUCTURE / ARRAYS										 */
/* ************************************************************* */
void	*ft_calloc(size_t count, size_t size);
void	*ft_calloc_fd(char *filename, size_t count, size_t sizeofvar);
void	ft_free_fd(char *filename);
void	ft_free_array_2d(char **array);
void	ft_free_array_int(int **array_int, int size);
void	ft_free_fd_new(char *filename);
void	ft_free_array_halt(char **farray, int failed);

// ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓	//

/* ************************************************************* */
/* ************************************************************* */
//GET_NEXT_LINE2 HELPERS
size_t	ft_strlen_gnl(char *s, int c);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff, int c);
int		ft_read_to_left_str2(int fd, char **left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_get_line(char *left_str);

#endif

/*
it will receive a t_list pointer and a size_t size,
this function will perform a mallloc, check if the malloc was successful, and return the pointer to the allocated memory
will add to the list the pointer to the allocated memory
it will works as garbage collector adding the pointer to the list

*/

#include "ft_mylib.h"

void	*ft_malloc(t_list *list, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		ft_printf("Error: malloc failed\n");
		exit(1);
	}
	ft_lstadd_back(&list, ft_lstnew(ptr));
	return (ptr);
}
# ft_lstclear
``` c 
void ft_lstclear(t_list **lst, void (*del)(void *));
```
<br>
<br>

# Manual
**Brief:**
Deletes and frees all elements of a linked list.

**File:** `ft_lstclear.c` / **Date:** 2024-06-22  
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**



**Description:**  
This function deletes and frees all the elements of the linked list pointed to by `lst`. The function `del` passed as a parameter is used to free the content of each element.

**Input Values:**  
* `lst`: The address of a pointer to a node.
* `del`: The address of the function used to delete the content of the node.

**Return Value:**  
* None.

**Note:**
- The list pointed to by `lst` will be set to NULL after the function completes.
- Ensure that the `del` function is valid and capable of correctly freeing the content of the nodes.

**Example:**  
```c
t_list *head = NULL;
// ... add elements to the list ...

ft_lstclear(&head, free);  // Delete and free all nodes in the list
// head is now NULL
```

<br>
<br>

# Code Explanation
**Source Code:**
``` C
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
```

**Comments:**
```C
void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    // Check if the list pointer, the head of the list, and the deletion function are valid
    if (!lst || !*lst || !del)  
        return ;

    // Iterate through the list
    while (*lst) 
    {
        // 1. Store the 'next' pointer of the current node
        tmp = (*lst)->next;  

        // 2. Delete the current node using the provided deletion function
        ft_lstdelone(*lst, del); 

        // 3. Move to the next node in the list
        *lst = tmp;           
    }

    // Set the head of the list to NULL to indicate an empty list
    *lst = NULL;              
}
```
# ft_lstmap
``` c 
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```
<br>
<br>

# Manual
**Brief:**
Iterates a list applying the function ’f’ to each node’s content and creating a new list resulting of the successive applications of the function ’f’.

**File:** `ft_lstmap.c` / **Date:** 2024-06-22  
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**



**Description:**  
Iterates the list ’lst’ and applies the function ’f’ to the content of each node. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed.

**Input Values:**
* `lst`: The address of a pointer to a node.
* `f`: The address of the function used to iterate on the list.
* `del`: The address of the function used to delete the content of a node if needed.

**Return Value:**  
* The new list.
* NULL if the allocation fails.

**Note:**  
-  The function returns NULL if the allocation fails or if the input list is empty.

**Example:**  
```c
// Function to increment an integer
void *increment(void *content) {
    int *num = (int *)content;
    (*num)++;
    return (num);
}

t_list *head = NULL;
// ... add elements to the list ...

t_list *new_list = ft_lstmap(head, increment, free); 
// new_list is a new list with each integer element incremented by 1.
```

<br>
<br>

# Code Explanation
**Source Code:**
``` C
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
```

```c
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *new_elem;
    void    *content;

    // Check if the list pointer, the mapping function, and the deletion function are valid
    if (!lst || !f || !del)
        return (NULL);

    new_lst = NULL; // Initialize the new list to NULL

    // Iterate through the original list
    while (lst)
    {
        // 1. Apply the mapping function 'f' to the content of the current node
        content = f(lst->content);

        // 2. Create a new node with the mapped content
        new_elem = ft_lstnew(content); 

        // 3. Check if the new node was created successfully
        if (!new_elem) 
        {
            // If allocation failed, clear the new list, free the mapped content, and return NULL
            ft_lstclear(&new_lst, del); 
            del(content);
            return (NULL);
        }

        // 4. Add the new node to the end of the new list
        ft_lstadd_back(&new_lst, new_elem); 

        // 5. Move to the next node in the original list
        lst = lst->next;
    }

    // Return the head of the new list
    return (new_lst);
}
```
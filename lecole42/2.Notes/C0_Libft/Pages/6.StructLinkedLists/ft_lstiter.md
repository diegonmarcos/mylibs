# ft_lstiter
``` c 
void ft_lstiter(t_list *lst, void (*f)(void *));
```
<br>
<br>

# Manual
**Brief:**
Iterates the list `lst` and applies the function `f` to the content of each node.

**File:** `ft_lstiter.c` / **Date:** 2024-06-22  
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**



**Description:**  
This function iterates through the linked list starting at the node pointed to by `lst`.  For each node, it applies the function `f` to the node's content.

**Input Values:**  
* `lst`: The address of a pointer to a node.
* `f`: A function pointer to a function that takes a `void *` argument and returns nothing.

**Return Value:**  
* None.

**Note:**  
- The function does not modify the list structure itself, only the content of each node.
- Ensure that the function `f` is valid and does not attempt to modify or free the list nodes themselves.

**Example:**  
```c
// Function to print the content of a node (assuming the content is a string)
void print_content(void *content) {
    printf("%s\n", (char *)content);
}

t_list *head = NULL;
// ... add elements to the list ...

ft_lstiter(head, print_content); // Print the content of each node in the list
```

<br>
<br>

# Code Explanation
**Source Code:**
``` C
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

```


**Comments:**
```C
void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    // Check if the list pointer is valid
    if (!lst)  
        return ;

    // Iterate through the list
    while (lst)
    {
        // 1. Apply the provided function 'f' to the content of the current node
        f(lst->content);

        // 2. Move to the next node in the list
        lst = lst->next;    
    }
}
```
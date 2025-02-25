# ft_lstnew
``` c 
t_list *ft_lstnew(void *content);
```
<br>
<br>

# Manual
**Brief:**
Creates a new node for a linked list.

**File:** `ft_lstnew.c` / **Date:** 2024-06-22  
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**



**Description:**
This function allocates memory for a new node in a linked list and initializes its members. The `content` field of the new node is set to the `content` argument, and the `next` field is set to `NULL`.

**Input Values:**
* `content`: The content to be stored in the new node. This can be a pointer to any data type.

**Return Value:**
* The newly created node (`t_list *`).
* `NULL` if memory allocation fails.

**Note:**
- The caller is responsible for freeing the memory allocated for the new node when it's no longer needed.
- You can use `ft_lstadd_front` or `ft_lstadd_back` to add the new node to an existing linked list.

**Example:**
```c
t_list *new_node = ft_lstnew("Hello, world!"); 
// Creates a new node with the string "Hello, world!" as its content.
```

<br>
<br>

# Code Explanation
**Source Code:**
``` C
t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	(*new_lst).next = NULL;
	return (new_lst);
}
```

**Comments:**
```C
t_list  *ft_lstnew(void *content)
{
    t_list  *new_lst;

    // Allocate memory for the new list node
    new_lst = (t_list *)malloc(sizeof(t_list)); 

    // Check if memory allocation was successful
    if (!new_lst)
        return (NULL);

    // Set the content of the new node
    new_lst->content = content; 

    // Set the 'next' pointer of the new node to NULL
    new_lst->next = NULL;  // Or (*new_lst).
```
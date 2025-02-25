sons : [ft_bzero](ft_bzero.md) [ft_malloc](ft_malloc)
tags : #memcopy

# ft_calloc
``` c 
void *ft_calloc(size_t count, size_t size);
```
<br>
<br>

# Manual
**Brief:**
Allocates memory for an array of `count` elements, each of size `size` bytes, and initializes all bytes to zero.

**File:** `ft_calloc.c` / **Date:** 2024-06-22
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**
* `stdlib.h `

**Description:**
The `ft_calloc()` function contiguously allocates enough space for `count` objects that are `size` bytes of memory each and returns a pointer to the allocated memory. The allocated memory is filled with bytes of value zero.

**Input Values:**
* `count`: The number of elements to be allocated.
* `size`: The size in bytes of each element.

**Return Value:**
* A pointer to the allocated memory. If the allocation fails, the function returns `NULL`.

**Note:**
- It is the caller's responsibility to free the allocated memory using the `free()` function when it is no longer needed.
- The calculation of `count * size` may result in integer overflow, leading to undefined behavior. Be mindful of the potential risks when using large values for `count` or `size`.

**Example:**
```c
int *arr = ft_calloc(5, sizeof(int)); 
// arr now points to a block of memory big enough to hold 5 integers, all initialized to zero.
```


<br>
<br>

# Code Explanation
**Source Code:**
``` C
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / count < size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}

```

``` c
void    *ft_calloc(size_t count, size_t size)
{
    unsigned char   *tmp;  // Pointer to store the allocated memory
    size_t          i;    // Loop counter (not used in this version)

    i = 0;  // Initialize loop counter (unnecessary here)

    // Handle cases where count or size is 0
    if (count == 0 || size == 0)
        return (malloc(0));  // Allocate a zero-sized block

    // Check for potential integer overflow during multiplication
    if (SIZE_MAX / count < size)
        return (NULL);  // Return NULL if overflow would occur

    // Allocate memory block of size count * size
    tmp = malloc(count * size);

    // Check if allocation was successful
    if (!tmp)
        return (NULL);  // Return NULL if allocation failed

    // Zero out the allocated memory block
    ft_bzero(tmp, count * size);

    // Return a pointer to the allocated and zeroed memory
    return (tmp);
}
```








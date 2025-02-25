sons : [ft_strlen](ft_strlen.md) [ft_strdup](ft_strdup.md) [ft_calloc](ft_calloc.md) [ft_strlcpy](ft_strlcpy.md)
tags : #memcopy


# ft_substr
``` c 
char *ft_substr(char const *s, unsigned int start, size_t len);
```
<br>
<br>

# Manual
**Brief:**  
Returns a substring from the string `s`.

**File:** `ft_substr.c` / **Date:** 2024-06-22  
**Author:** Diego N. Marcos <dnepomuc@student.42barcelona.com>

**Library/Header:**



**Description:**  
Allocates (with `malloc(3)`) and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`.

**Input Values:**  
* `s`: The string from which to create the substring.
* `start`: The start index of the substring in the string `s`.
* `len`: The maximum length of the substring.

**Return Value:**  
* The substring. 
* `NULL` if the allocation fails.

**Note:**  
- If `start` is greater than or equal to the length of `s`, an empty string is returned.
- If `len` is greater than the number of characters remaining in `s` starting from `start`, the substring will contain all the remaining characters from `start` until the end of `s`.
- It is the caller's responsibility to free the memory allocated for the substring.

**Example:**  
```c
char *str = "Hello, world!";
char *substr = ft_substr(str, 7, 5);  

printf("%s\n", substr); // Output: world
free(substr);
```

<br>
<br>

# Code Explanation
**Source Code:**
```c
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > (s_len - (size_t)start))
		len = (s_len - (size_t)start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
```

**Explanation**
``` C
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*str;  // Pointer to the new substring
	size_t		s_len; // Length of the source string

	s_len = ft_strlen(s); // Calculate the length of the source string

	// Handle cases where the input string is NULL or the start index is out of bounds
	if (!s) 
		return (NULL);  // Return NULL if the source string is NULL
	if (start > s_len)
		return (ft_strdup("")); // Return an empty string if start is beyond the end of the string

	// Adjust the length if it exceeds the available characters from the start index
	if (len > (s_len - (size_t)start))
		len = (s_len - (size_t)start); 

	// Allocate memory for the substring (including space for the null terminator)
	str = ft_calloc(len + 1, sizeof(char)); 
	if (!str)
		return (NULL); // Return NULL if memory allocation fails

	// Copy the substring from the source string to the new string
	ft_strlcpy(str, s + start, len + 1); 
	return (str); // Return the new substring
}

```


# LIBFT

# Type
## 1. I/O Printers
- [ft_putchar_fd](ft_putchar_fd.md): Writes a single character to a given file descriptor. 
    ```C
    void    ft_putchar_fd(char c, int fd)
    ```
- [ft_putstr_fd](ft_putstr_fd.md): Writes a string to a given file descriptor.
    ```C
    void    ft_putstr_fd(char *s, int fd)
    ```
- [ft_putendl_fd](ft_putendl_fd.md): Writes a string to a given file descriptor, followed by a newline.
    ```C
    void    ft_putendl_fd(char *s, int fd)
    ```
- [ft_putnbr_fd](ft_putnbr_fd.md): Writes an integer to a given file descriptor.
    ```C
    void    ft_putnbr_fd(int n, int fd)
    ```

## 2. String Classification
- [ft_strlen](ft_strlen.md): Calculates the length of a string.
    ```C
    size_t  ft_strlen(const char *s) // Calculates the length of a string.
    ```
- [ft_isalpha](ft_isalpha.md): Checks if a character is alphabetic.
    ```C
    int     ft_isalpha(int c)
    ```
- [ft_isdigit](ft_isdigit.md): Checks if a character is a digit.
    ```C
    int     ft_isdigit(int c)
    ```
- [ft_isalnum](ft_isalnum.md): Checks if a character is alphanumeric.
    ```C
    int     ft_isalnum(int c)
    ```
- [ft_isascii](ft_isascii.md): Checks if a character is a valid ASCII character.
    ```C
    int     ft_isascii(int c)
    ```
- [ft_isprint](ft_isprint.md): Checks if a character is printable.
    ```C
    int     ft_isprint(int c)
    ```

## 3. String Formatting
- [ft_memset](ft_memset.md): Fills a block of memory with a specific byte.
    ```C
    void    *ft_memset(void *b, int c, size_t len)
    ```
- [ft_bzero](ft_bzero.md): Sets a block of memory to zero.
    ```C
    void    ft_bzero(void *s, size_t n)
    ```
- [ft_toupper](ft_toupper.md): Converts a character to uppercase.
    ```C
    int     ft_toupper(int c)
    ```
- [ft_tolower](ft_tolower.md): Converts a character to lowercase.
    ```C
    int     ft_tolower(int c)
    ```
- [ft_atoi](ft_atoi.md): Converts a string to an integer.
    ```C
    int     ft_atoi(const char *str)
    ```
- [ft_itoa](ft_itoa.md): Converts an integer to a string.
    ```C
    char    *ft_itoa(int n)
    ```
- [ft_strmapi](ft_strmapi.md): Applies a function to each character of a string, passing the index as an argument.
    ```C
    char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
    ```
- [ft_striteri](ft_striteri.md): Applies a function to each character of a string, passing the index as an argument.
    ```C
    void    ft_striteri(char *s, void (*f)(unsigned int, char*))
    ```

## 4. String Search, Compare and Subs
- [ft_memcmp](C0_Libft/Pages/4.StringSearchCompareSubs/ft_memcmp.md): Compares two blocks of memory.
    ```C
    int     ft_memcmp(const void *s1, const void *s2, size_t n)
    ```
- [ft_memchr](C0_Libft/Pages/4.StringSearchCompareSubs/ft_memchr.md): Searches for a character in a block of memory.
    ```C
    void    *ft_memchr(const void *s, int c, size_t n)
    ```
- [ft_strchr](ft_strchr.md): Locates the first occurrence of a character in a string.
    ```C
    char    *ft_strchr(const char *s, int c)
    ```
- [ft_strrchr](ft_strrchr.md): Locates the last occurrence of a character in a string.
    ```C
    char    *ft_strrchr(const char *s, int c)
    ```
- [ft_strnstr](ft_strnstr.md): Locates a substring within a string.
    ```C
    char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
    ```
- [ft_strncmp](ft_strncmp.md): Compares two strings up to a specified length.
    ```C
    int     ft_strncmp(const char *s1, const char *s2, size_t n)
    ```

## 5. Memory Copy, Move and Split
- [ft_memcpy](ft_memcpy.md): Copies a block of memory from one location to another.
    ```C
    void    *ft_memcpy(void *dst, const void *src, size_t n)
    ```
- [ft_memmove](ft_memmove.md): Moves a block of memory from one location to another, handling overlapping regions.
    ```C
    void    *ft_memmove(void *dst, const void *src, size_t len)
    ```
- [ft_strlcpy](ft_strlcpy.md): Copies a string to another string, with size bounds.
    ```C
    size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
    ```
- [ft_strlcat](ft_strlcat.md): Concatenates two strings, with size bounds.
    ```C
    size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
    ```
- [ft_strjoin](ft_strjoin.md): Joins two strings together.
    ```C
    char    *ft_strjoin(char const *s1, char const *s2)
    ```
- [ft_strdup](ft_strdup.md): Creates a duplicate of a string.
    ```C
    char    *ft_strdup(const char *s1)
    ```
- [ft_strtrim](ft_strtrim.md): Removes leading and trailing whitespace from a string.
    ```C
    char    *ft_strtrim(char const *s1, char const *set)
    ```
- [ft_substr](C0_Libft/Pages/5.MemoryCopyMoveSplit/ft_substr.md): Extracts a substring from a string.
    ```C
    char    *ft_substr(char const *s, unsigned int start, size_t len)
    ```
- [ft_split](ft_split.md): Splits a string into an array of substrings based on a delimiter.
    ```C
    char    **ft_split(char const *s, char c)
    ```
- [ft_calloc](ft_calloc.md): Allocates memory and sets it to zero.
    ```C
    void    *ft_calloc(size_t count, size_t size)
    ```


## 6. Struct - Linked Lists
- [ft_lstnew]()
	```C
	t_list *ft_lstnew(void *content);
	```
- [ft_lstadd_front]()
	```C
	void ft_lstadd_front(t_list **lst, t_list *new);
	```
- [ft_lstsize]()
	``` c 
	int ft_lstsize(t_list *lst);
	```
- [ft_lstlast]()
	``` c 
	t_list *ft_lstlast(t_list *lst);
	```
- [ft_lstadd_back]()
	``` c 
	void ft_lstadd_back(t_list **lst, t_list *new);
	```
- [ft_lstdelone]()
	``` c
	void ft_lstdelone(t_list *lst, void (*del)(void*));
	```
- [ft_lstclear]()
	``` c
	void ft_lstclear(t_list **lst, void (*del)(void*));
	```
- [ft_lstiter]()
	``` c
	void ft_lstiter(t_list *lst, void (*f)(void*));
	```
- [ft_lstmap]()
	``` c 
	t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
	```
##
---
# Complexity Level
## Level 1
- **1. I/O Printers:**
    - `ft_putchar_fd`
    - `ft_putstr_fd`
    - `ft_putendl_fd`
    - `ft_putnbr_fd`
- **2. String Classification:**
    - `ft_isalpha`
    - `ft_isdigit`
    - `ft_isalnum`
    - `ft_isascii`
    - `ft_isprint`
    - `ft_strlen  `
- **3. String Formatting:**
    - `ft_memset`
    - `ft_bzero`
    - `ft_toupper`
    - `ft_tolower`
- **4. String Search, Compare and Subs:**
    - `ft_strchr` 
    - `ft_strrchr` 
    - `ft_strncmp` 
- **5. Memory Copy, Move and Split:**
    - `ft_memcpy`
    - `ft_memmove`
- **6. Struct - Linked Lists:**
    - `ft_lstnew`
    - `ft_lstadd_front`
    - `ft_lstsize`
    - `ft_lstlast`
    - `ft_lstadd_back`
    - `ft_lstdelone`
## Level 2
- **3. String Formatting:**
    - `ft_atoi`
    - `ft_itoa`
    - `ft_strmapi`
    - `ft_striteri`
- **4. String Search, Compare and Subs:**
    - `ft_memcmp`
    - `ft_memchr`
    - `ft_strnstr`
    - `ft_substr`
- **5. Memory Copy, Move and Split:**
    - `ft_strlcpy`
    - `ft_strlcat`
    - `ft_strjoin`
    - `ft_strdup`
    - `ft_strtrim`
- **6. Struct - Linked Lists:**
    - `ft_lstclear`
    - `ft_lstiter`
## Level 3
- **5. Memory Copy, Move and Split:**
    - `ft_split` 
    - `ft_calloc`
- **6. Struct - Linked Lists:**
    - `ft_lstmap` 

# .
---
# . 
# Dependencies
	Analysis of the interconnections

**Interconnection Overview:**

Character Classification:
```
     ft_isalnum
        |     \
     ft_isalpha   ft_isdigit
```

Memory Manipulation:
```
     ft_calloc 
       |    \
    malloc   ft_bzero
                  |
                memset
```
```
    ft_memmove <---- ft_memcpy
       |
    move_memory    
```

String Manipulation:
```
   ft_strjoin   ft_strtrim   ft_split
          \      /         /
           ft_substr      /
                     ft_calloc
                     ft_free
```
```
   ft_strmapi
       |
    ft_strdup
```
```
   ft_strnstr
      |   \
  ft_strlen  ft_strncmp
```
```
   ft_strtrim
     |    \
 ft_strlen  ft_strchr
```

Integer-String Conversion:
```
      			ft_itoa 
   		 /		   |      	\
ft_calloc 	ft_digit_count   comp
                      		  |
                        ft_putnbr_fd
                              |
                         ft_putstr_fd
```
File Descriptor Output:
```
  ft_putendl_fd     ft_putnbr_fd
       | \             /
       |  ft_putstr_fd
       |       |
       \-------ft_putchar_fd
```



1. **Character Classification:**
   - `ft_isalnum` depends on
      - `ft_isalpha` and `ft_isdigit`.

2. **Memory Manipulation:**
   - `ft_calloc` depends on
      -  `malloc` and `ft_bzero`.
   - `ft_bzero` depends on
      - `memset`.
   - `ft_memcpy` is used within
      - `ft_memmove` (in the case of non-overlapping memory).
   - `ft_strdup` depends on
      - `ft_strlen`, `malloc`, and `ft_memcpy` (or `ft_strlcpy`).

3. **String Manipulation:**
   - `ft_strjoin`, `ft_strtrim`, and `ft_split` use
      - `ft_substr`.
   - `ft_split` also depends on
      - `ft_calloc` and `ft_free`.
   - `ft_strmapi` depends on
      - `ft_strdup`.
   - `ft_strnstr` depends on
      - `ft_strlen` and `ft_strncmp`.
   - `ft_strtrim` depends on
      - `ft_strlen` and `ft_strchr`.

4. **Integer-String Conversion:**
   - `ft_itoa` depends on
      - `ft_calloc`, `ft_digit_count` (a helper function), and `comp` (another helper function).
   - `ft_putnbr_fd` uses
      - `ft_itoa` and `ft_putstr_fd`.

5. **File Descriptor Output:**
   - `ft_putendl_fd` and `ft_putnbr_fd` depend on
      -  `ft_putstr_fd` and `ft_putchar_fd`.

#### LibC Functions #1
- ft_strlen
- ft_memcpy
- ft_memset
- ft_bzero
- ft_memmove
- ft_memcmp
- ft_memchr

#### LibC Functions #2
- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint

#### LibC Functions #3
- ft_toupper
- ft_tolower
- ft_strchr
- ft_strrchr

#### LibC Functions #4
- ft_strlcat
- ft_strlcpy
- ft_atoi
- ft_strnstr
- ft_strncmp
- ft_calloc
- ft_strdup

#### Additional Functions #1
- ft_substr
- ft_strjoin
- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

#### Additional Functions #2
- ft_strmapi
- ft_striteri
- ft_strtrim
- ft_split
- ft_itoa



# .
---
# .
# Keynotes

#### Backend Organization and Categorization:
	
1. Granularity Levels
	1. High Level	```
		-Scope (System-wide/Macro/Holistic)
		-Abstraction (Conceptual/Big-Picture/Abstract)
		-Complexity (Sophistication)
	1. Low Level 	```
		-Scope (Local/Micro/Atomic)
		-Abstraction (Implementation-specific/Tactical/Concrete)
		-Complexity (Fundamental/Basic/Elemental)

1. Granularity Levels
	1. High Level
		1. Behavior
		2. Complexity
	2. Low Level
		1. Operational Behavior
		2. Operational Complexity

1. Organize by:
	1. Behavior `Observing how a function acts and interacts with its surroundings. Categorize by its outputs, exploring then its demanding inputs and actions`
		1. Individual Outputs `isolated independent outputs and actions´
		2. Propose  `what its output means in conjuction with the enviroments output`
	2. Operational `Understanding the internal mechanisms of a function. How does it work internally to achieve its result`
		1. Scope
			1. Macro System-wide
			2. Micro Local
		2. Complexity
			1. Low
			2. High
#### Frontend Organization and Categorization

1. Implementation and Maintenance Scalability (Source Code Readability)
2. Safety
3. Performance
4. UX





#### 1. Behavioral Mode
1. Management Functions
		1. Allocators
		2. Manipulators
2. String Manipulation Functions
	1. Comparison
	2. Concatenation
	3. Copying
	4. Length
	5. Search
3. Character Functions
	1. Char Type
4. Input/Output Functions
	1. Standart IO
	2. File IO

#### 2. Complexity Level
	table with 3 levels vs Intercation mode


# Takeaways

 functions  be categorized based on how they interact with and strings. Here are some primary categories:

**1. Management Functions:**

- **Allocation:** `malloc()`, `calloc()`, `realloc()` - These functions allocate blocks of memory dynamically during program execution.
- **Deallocation:** `free()` - This function releases memory blocks previously allocated by `malloc()`, `calloc()`, or `realloc()`.
- **Memory manipulation:** `memcpy()`, `memset()`, `memmove()` - These functions copy, set, or move blocks of memory.

**2. String Manipulation Functions:**

- **String comparison:** `strcmp()`, `strncmp()` - These functions compare two strings lexicographically.
- **String concatenation:** `strcat()`, `strncat()` - These functions append one string to the end of another.
- **String copying:** `strcpy()`, `strncpy()` - These functions copy one string to another.
- **String length:** `strlen()` - This function calculates the length of a string.
- **String searching:** `strchr()`, `strrchr()`, `strstr()` - These functions search for the occurrence of a character or a substring within a string.

**3. Character Functions:**

- **Character type checking:** `isalpha()`, `isdigit()`, `isalnum()`, `islower()`, `isupper()`, etc. - These functions check whether a character belongs to a specific category (e.g., alphabetic, numeric, alphanumeric, lowercase, uppercase).

**4. Input/Output Functions:**

- **Standard input/output:** `printf()`, `scanf()`, `getchar()`, `putchar()` - These functions handle formatted and unformatted input and output operations.
- **File input/output:** `fopen()`, `fclose()`, `fread()`, `fwrite()`, `fprintf()`, `fscanf()` - These functions handle input and output operations on files.

**Why these categories matter in C:**

- **Memory management:** C requires explicit memory management, meaning you need to allocate and deallocate memory manually. Understanding memory management functions is crucial to avoid memory leaks and segmentation faults.
- **String manipulation:** C treats strings as arrays of characters. String manipulation functions provide efficient ways to work with strings, which are fundamental to many programming tasks.
- **Character classification:** These functions help in parsing and validating input, as well as in performing various text processing operations.
- **Input/Output:** These functions are essential for interacting with the user and the file system.

By understanding these categories and the functions within them, you can write more efficient, robust, and maintainable C code.

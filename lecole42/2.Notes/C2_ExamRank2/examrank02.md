# Exam Rank 02
---
## String Manip
- **string_manip** -  String manipulation functions.
	- L1
	- `ft_putstr.c` - Prints a string to the standard output.
	- `ft_strcpy.c` - Copies a string to another.
	- `ft_strlen.c` - Calculates the length of a string.
	- ~~`ft_swap.c`~~ - Swaps the values of two variables.
	- ~~`ft_atoi.c`~~ - Converts a string to an integer.
	- `ft_strcmp.c` - Compares two strings.
	- `ft_strcspn.c` - Calculates the length of the initial segment of a string not containing any characters from another string.
	- `ft_strdup.c` - Duplicates a string.
	- `ft_strpbrk.c` - Locates the first occurrence of any character from a string in another string.
	- `ft_strrev.c` - Reverses a string.
	- `ft_strspn.c` - Calculates the length of the initial segment of a string containing only characters from another string.
	- L3
	- `ft_atoi_base.c` - Converts a string to an integer in a given base.
	- L4
	- ==`ft_itoa.c`==  - Convert string to a integer.
## Bitwise Operations
- **L2_bitwise** -  Bit manipulation functions.
	- `bitwise.c` - Performs bitwise operations on numbers.
	- `graycode.c` - Generates a Gray code sequence.
	- ~~`print_bits.c`~~ - Prints the binary representation of a number.
	- ==`reverse_bits.c`== - Reverses the bits of a number.
	- `swap_bits.c` - Swaps two bits in a number.

## Linked List
- L3
	- `ft_list_remove_if.c` - Removes elements from a linked list based on a condition.
	- `ft_list_size.c` - Calculates the size of a linked list.
	- `ft_list_foreach.c` - Applies a function to each element of a linked list.
## Algorithms
- **algos_string_manip:** 
	- L1
    - `paramsum.c` - Prints the number of arguments passed to the program.
    - `last_word.c` - Prints the last word of a string.
    - `repeat_alpha.c` - Repeats the characters of a string.
    - `rev_print.c` - Prints a string in reverse.
    - ~~`rot_13.c`~~ - 'z' becomes 'm'
    - `rotone.c` -  'z' becomes 'a'
    - `search_and_replace.c` - Replaces occurrences of a character in a string.
    - `ulstr.c` - Alternates the case of characters in a string.
    - `epur_str.c` - Removes extra spaces from a string.
    - ~~`expand_str.c`~~ - Expands a string by repeating characters.
    - ~~`rstr_capitalizer.c`~~ - Capitalizes the first letter of each word in a string in reverse order.
    - `str_capitalizer.c` - Capitalizes the first letter of each word in a string.
      - L2
     - `alpha_mirror.c` - Replaces characters with their mirrored counterparts in the alphabet.
    - `camel_to_snake.c` - Converts a string from camel case to snake case.
    - `snake_to_camel.c` - Converts a string from snake case to camel case.
    - L3
    - `ft_range.c` - Creates an array of integers within a given range.
	- `ft_rrange.c` - Creates an array of integers within a given range in reverse order.
    - L4
    - ~~`rev_wstr.c`~~ - Reverses the order of words in a string.
    - `rostring.c` - Rotates the words in a string.
- **algos_string_search_sorting:**
	- L1
	- `first_word.c` - Finds the first word in a string.
	- L2
    - `inter.c` - Finds the common characters between two strings.
    - `wdmatch.c` - Checks if a word is present in a string.
    - ==`hidenp.c`== - Checks if a string is hidden in another string.
	- L4
    - `bubble_sort_int_tab.c` - Sorts an array of integers.
- **arithmetic**
	- **L2**
    - `do_op.c` - Performs a basic arithmetic operation on two numbers.
    - `is_power_of_2.c` - Checks if a number is a power of two.
    - `max.c` - Finds the maximum value in an array of integers.
	- **L3**
    - `add_prime_sum.c` - Calculates the sum of prime numbers up to a given number.
    - `lcm.c` - Calculates the least common multiple of two numbers.
    - `pgcd.c` - Calculates the greatest common divisor of two numbers.
    - `print_hex.c` - Prints a number in hexadecimal format.
    - `fprime.c` - Calculates the prime factors of a number.
    - 
- **algos_linklst_manip
	- `sort_list.c` - Sorts a linked list.
	- `flood_fill.c` -  Change color of the neighbor if same color.



# Notes
## Binaries
- 0: 0
- 1: 1
- 2: 10
- 3: 11
- 4: 100
- 5: 101
- 6: 110
- 7: 111
- 8: 00001000
- 9: 00001001
## Bitwise Operations
**1. AND (&)**
- **Description:** Compares each bit of the first operand to the corresponding bit of the second operand. If both bits are 1, the corresponding result bit is set to 1. Otherwise, the result bit is 0.  
- **Example:** `5 & 3 = 1`
    - 5 in binary: 101
    - 3 in binary: 011
    - Result (101 & 011): 001 (which is 1 in decimal)

**2. OR (|)**
- **Description:** Compares each bit of the first operand to the corresponding bit of the second operand. If at least one of the bits is 1, the corresponding result bit is set to 1. Otherwise, the result bit is 0.  
- **Example:** `5 | 3 = 7`
    - 5 in binary: 101
    - 3 in binary: 011
    - Result (101 | 011): 111 (which is 7 in decimal)

**3. XOR (^)**
- **Description:** Compares each bit of the first operand to the corresponding bit of the second operand. If the bits are different, the corresponding result bit is set to 1. Otherwise, the result bit is 0. (Exclusive OR)  
- **Example:** `5 ^ 3 = 6`
    - 5 in binary: 101
    - 3 in binary: 011
    - Result (101 ^ 011): 110 (which is 6 in decimal)

**4. NOT (~)**
- **Description:** Inverts all the bits of a single operand. 0s become 1s, and 1s become 0s. (This is a unary operator, meaning it works on one value).
- **Example:** `~5 = -6` (This result depends on the specific system and how negative numbers are represented, often using two's complement.)

**5. Left Shift (<<)**
- **Description:** Shifts the bits of the first operand to the left by the number of positions specified by the second operand. New bits on the right-hand side are filled with 0s.  
- **Example:** `5 << 1 = 10`
    - 5 in binary: 101
    - Shifted left by 1: 1010 (which is 10 in decimal)

**6. Right Shift (>>)**
- **Description:** Shifts the bits of the first operand to the right by the number of positions specified by the second operand. New bits on the left-hand side are filled in, depending on the sign of the original number (often with 0s for positive numbers and 1s for negative numbers in two's complement).  
- **Example:** `5 >> 1 = 2`
    - 5 in binary: 101
    - Shifted right by 1: 010 (which is 2 in decimal)


## attempts

rever bit, 
hidenp,
itoa, 


rot_13
print_bits
expand_str //

ft_swap 30min
ft_atoi 1h
rstr_capitalizer 1h15
rev_wstr.c - failed here no time

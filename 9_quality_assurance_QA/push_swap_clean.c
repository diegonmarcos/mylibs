/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:57:51 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/16 20:03:37 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// SECTIONS
//##############################################################################

// HEADER
			// DEBBUGING PRINTERS & LOGGERS

		// UTILS/STRING MANIPULATION, MEMORY MANAGEMENT AND GENERAL UTILS
		// UTILS/LINKED LIST MANIPULATION
		// UTILS/SORTING/LINKED LIST

	// ERROR HANDLING/HELPERS
	// ERROR HANDLING

	// ALGORITHMS AND STACK/HELPERS
	// STACK MOVES
	// SORTING ALGORITHMS
	
// MAIN

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	halt_exit(int status, char *description);
void	halt_exit_(int status);

// MACROS

// DATA STRUCTURE
typedef struct s_list
{
    int             value;
    int             index;
    struct s_list   *next;
    struct s_list   *prev;
} t_list;


//##############################################################################
// UTILS/STRING MANIPULATION, MEMORY MANAGEMENT AND GENERAL UTILS
//##############################################################################
void ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (dst == (void *)0 && src == NULL)
		return;
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
}

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

void free_array_2d(char **array)
{
	int i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}
void print_linked_list_field(t_list *stack, char *field) 
{
	if (stack == NULL) {
		printf("Empty list\n");
		return;
	}

	t_list *current = stack;
	int first_node = 1; 														// do...while alternative

	while (first_node || current != stack)
	{
		if (!ft_strncmp(field, "value", ft_strlen("value") + 1))
			printf("%d", current->value);
		else if (!ft_strncmp(field, "index", ft_strlen("index") + 1))
			printf("%d", current->index);
		else
			printf("%d", current->value); 										// Default to printing value

		current = current->next;

		if (current == stack)
			break; 																// Break if we have reached the start again

		if (current != stack)
			printf(", "); 														// Print comma if not the last element

		first_node = 0;
	}
	printf("\n");
}

void print_linked_list_field_old(t_list *stack, char *field) 
{
    if (stack == NULL) {
        printf("Empty list\n");
        return;
    }

    t_list *current = stack;
    int first_node = 1; 														// do...while alternative

    while (first_node || current != stack)
    {
        if (!ft_strncmp(field, "value", ft_strlen("value") + 1))
            printf("%d", current->value);
        else if (!ft_strncmp(field, "index", ft_strlen("index") + 1))
            printf("%d", current->index);
        else
            printf("%d", current->value); 										// Default to printing value

        current = current->next;

        if (current != stack)
            printf(", "); 														// Print comma if not the last element

        first_node = 0;
    }
    printf("\n");
}

char **ft_split(const char *str, char c)
{
    int i, j, k;
    char **array;
    int token_count = 1;

																				// Count the number of tokens
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            token_count++;
        i++;
    }

																				// Allocate memory for the array of tokens
    array = (char **)malloc(sizeof(char *) * (token_count + 1));
    if (!array)
        return (NULL);

																				// Split the string into tokens
    i = 0;
    j = 0;
    while (str[i])
    {
    																				// Allocate memory for each token
        k = 0;
        while (str[i + k] && str[i + k] != c)
            k++;
        array[j] = (char *)malloc(sizeof(char) * (k + 1));
        if (!array[j])
        {
            free_array_2d(array);
            return (NULL);
        }

    																				// Copy the token
        k = 0;
        while (str[i] && str[i] != c)
            array[j][k++] = str[i++];
        array[j][k] = '\0';

    																				// Skip the delimiter
        if (str[i])
            i++;
        j++;
    }
    array[j] = NULL; 																// Null-terminate the array of tokens

    return (array);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && !num[1])
	{
		return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void ft_swap_pointers(t_list **a, t_list **b)
{
	t_list *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
//##############################################################################
// UTILS/LINKED LIST MANIPULATION
//##############################################################################
// Create a new node for the circular doubly linked list
t_list *ft_lstnew(int value, int index) 
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));

    if (!new_node) 
	{
        printf("Memory allocation failed in ft_lstnew\n");
        halt_exit_(1);
    }
    new_node->value = value;														// Assign the value
    new_node->index = index;														// Assign the index
    new_node->next = new_node;														// Point to itself initially
    new_node->prev = new_node;														// Point to itself initially
    return new_node;
}

// Add a node to the end of a circular doubly linked list

void ft_lstadd_back(t_list **stack, t_list *new_node) 
{
	if (!*stack)																	// If the list is empty
	{
    	*stack = new_node;															// The new node is the head
    	new_node->next = new_node;													// Point to itself
    	new_node->prev = new_node;													// Point to itself
    } 
	else 
	{
		t_list *tail = (*stack)->prev; // Get the tail node

    	new_node->next = *stack;													// Point to the head
    	new_node->prev = tail;														// Point to the tail
    	tail->next = new_node;														// Tail points to the new node
    	(*stack)->prev = new_node;													// Head points to the new node
    }
}

// Get the size of a circular doubly linked list
int ft_lstsize(t_list *lst) 
{
    if (!lst) 
		return 0;

    int i;
	t_list *current;

	i = 1;
    current = lst;
    while (current->next != lst) 
	{
        i++;
        current = current->next;
    }
    return i;
}

// Free the circular doubly linked list
void ft_free_list(t_list *stack) 
{
    if (stack == NULL) 
        return; 																		// Nothing to free if the list is empty

    t_list *current;
    t_list *temp;
    
    current = stack->next;
    if (current != stack)																// Iterate only if there are more than one element
    {
        while (current != stack) 
        {
            temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Free the head node
    free(stack);
}

// Find the minimum value node in a circular linked list (excluding a given index)
t_list *find_min_node(t_list *stack) 
{
    if (!stack) return NULL;

    t_list *min_node = NULL;
    t_list *current = stack;
    int first_iteration = 1;

    while (first_iteration || current != stack) 
	{
        if (min_node == NULL || current->value < min_node->value) 
		{
            min_node = current;
        }
        current = current->next;
        first_iteration = 0;
    }

    return min_node;
}

//##############################################################################
// UTILS/SORTING/LINKED LIST
//##############################################################################
// Assign indexes to the nodes of the circular linked list based on their sorted order
void index_stack(t_list **stack) 
{
    if (!*stack) return;

    int size = ft_lstsize(*stack);
    int *values = malloc(sizeof(int) * size);
    if (!values) {
        fprintf(stderr, "Memory allocation failed in index_stack\n");
        exit(1);
    }

    t_list *current = *stack;
    // Copy values to the array
    for (int i = 0; i < size; i++) {
        values[i] = current->value;
        current = current->next;
    }

    // Sort the array (using bubble sort for simplicity)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    // Assign indexes based on sorted values
    current = *stack;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (current->value == values[j] && current->index == -1)
            {
                current->index = j;
            }
        }
        current = current->next;
    }
    free(values);
}

static t_list *get_next_min(t_list **stack) {
	t_list *head = *stack;
    t_list *min_node = NULL;
    int first_iteration = 1;

    if (head == NULL)
        return (NULL);

    while (first_iteration || head != *stack) {
        if (head->index == -1 && (min_node == NULL || head->value < min_node->value))
            min_node = head;
        head = head->next;
        first_iteration = 0;
    }

    return (min_node);
}

//##############################################################################
// ERROR HANDLING/HELPERS
//##############################################################################
void	halt_exit_(int status)
{
	if(status == 1)
	{
		write(2, "Error\n", 6);
		//exit(status);
	}
	//exit(status);
}

void	halt_exit(int status, char *description)
{
	if(1) 																			// for debugging and the first 1 is the swicth to turn on/off the debugging
		printf("Reason: %s\n", description);
	if(status == 1)
	{
		write(2, "Error\n", 6);
		exit(status);
	}

	exit(status);
}

t_list	*array_to_d_linked_list(char **argv)
{
    t_list	*tmp;
    int		i;
	t_list	*stack ;
	stack = NULL;
    i = 0;
    while (argv[i])
    {
        tmp = ft_lstnew(ft_atoi(argv[i]), -1);
        ft_lstadd_back(&stack, tmp);
        i++;
    }
	return (stack);
}

void add_index_numbers(t_list *list)
{
    t_list	*node;
    int		index;

    index = 0;
	node = get_next_min(&list);
    while (node)
    {
        node->index = index++;
		node = get_next_min(&list);
    }
}

// ##############################################################################
// DEBBUGING PRINTERS & LOGGERS
// ##############################################################################
void print_linkedlist_debbuging(t_list *head, int iterator, char* name) 
{
    FILE *output_file = fopen("debbuging.txt", "a"); 

    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(output_file, "--------------------\n"); fflush(output_file);
    fprintf(output_file, "Linked List Values:\n"); fflush(output_file);
    fprintf(output_file, "%s\n", name); fflush(output_file);
    fprintf(output_file, "Iteration: %d\n", iterator); fflush(output_file);

    if(head == NULL)
    {
        fprintf(output_file, "(null)\n"); fflush(output_file); // Print "(null)" 
    } 
    else 
    {
        t_list *current = head;
        int switch_on = 1;

        while (current != head || switch_on) {
            switch_on = 0;
            fprintf(output_file, "%d ", current->value); fflush(output_file);
            current = current->next;
        }
        fprintf(output_file, "\n"); fflush(output_file);
    }

    fprintf(output_file, "--------------------\n\n"); fflush(output_file);

    fclose(output_file); // Close the file only once at the end
}

void print_array_debbugging(int *arr, int size, int iterator)
{
    FILE *output_file = fopen("debbuging.txt", "a"); // Open file in append mode=write at the end of the file

    if (output_file == NULL) {
        perror("Error opening output file");
        return;
    }

    fprintf(output_file, "--------------------\n");
    fprintf(output_file, "Iteration: %d\n", iterator);
    fprintf(output_file, "Array:\n");

    for (int i = 0; i < size; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    fprintf(output_file, "\n");
    fprintf(output_file, "--------------------\n\n");

	fclose(output_file);
}

//##############################################################################
// ALGORITHMS AND STACK/HELPERS
//##############################################################################
int	is_sorted_array_int(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return 0;
		}
	}
	return 1;
}
int	is_sorted_array_char(char **arr)
{
	int i;

	i = 1;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) < ft_atoi(arr[i - 1]))
			return 0;
		i++;
	}
	return 1;
}
int is_sorted_linked_list(t_list *stack)
{
	t_list *current = stack;
	do {
		if (current->value > current->next->value && current->next != stack) 
		{
			return 0;
		}
		current = current->next;
	} while (current != stack);
	return 1;
}

//##############################################################################
// ERROR HANDLING
//##############################################################################
void	check_args_2(char **argv)
{

	int	array_int;
	int i;

	i = 0;
	while (argv[i])
	{
		array_int = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i])) 													//check if the input is a number
		{
			halt_exit_(1);
		}
		if (ft_contains(array_int, argv, i) == 1) 								//check if there are duplicates
		{
			halt_exit_(1);
		}
		if (array_int < INT_MIN || array_int > 2147483647) 							//check if the number is within the integer range
		{
			halt_exit_(1);
		}
		if (is_sorted_array_char(argv) == 1)										//check if the array is already sorted
		{
			halt_exit_(0);
		}
		i++;
	}
}
char	**check_args_1(int argc, char **argv)
{
	char	**argv_1;
	argv_1 = NULL;


	argv_1 = NULL;
	if(argc < 2)
	{
		halt_exit_(1);
	}
	else if(argc == 2)
	{
		argv_1 = ft_split(argv[1], ' ');
		check_args_2(argv_1);
	}
	else if(argc > 2)
	{
		argv_1 = (char **)malloc(argc * sizeof(char *)); 						// for garbage collection efficiency/mimicing ft_split
		ft_memcpy(argv_1, argv + 1, argc * sizeof(char *)); 					// argv+1 to skip the program name!!!
		check_args_2(argv_1);
	}
	return (argv_1);
}
//##############################################################################
// STACK MOVES
//##############################################################################

/* 
- Rotate the stack.
- Direction is 'r' for up coounter-clockwise(head to tail) and
	'rr' for clockwise(tail to head)
*/
void	rotate(char *direction, char stack_name, t_list **stack) 
{
	if (*stack == NULL || (*stack)->next == *stack)
		return; 																	// Nothing to rotate with 0 or 1 element

	t_list *head = *stack;
	t_list *tail = (*stack)->prev;

	if (ft_strncmp(direction, "r", sizeof("r")) == 0) 								// Rotate up (ra, rb) - counter-clockwise - head to tail
		*stack = head->next;
	else if (ft_strncmp(direction, "rr", sizeof("rr")) == 0)  						// Rotate down (rra, rrb) - clockwise - tail to head
		*stack = tail;
	else 
		return;
		printf("%s%c\n", direction, stack_name); 										// Print the command for the checker
}

/* 
- Push the top element of statck.
- Direction is 'a' for pa from B to A,  and 'b' for pb from A to B 
*/
void push(char direction, t_list **stack_a_, t_list **stack_b_)
{
    t_list **stack_a = stack_a_;
    t_list **stack_b = stack_b_;
    t_list **src_stack = (direction == 'a') ? stack_b : stack_a;				// Determine source and destination stacks based on direction
    t_list **dest_stack = (direction == 'a') ? stack_a : stack_b;
    if (*src_stack == NULL)
        return;																	// Nothing to push from

    t_list *node_to_move = *src_stack;
																				 // Remove node from source stack
    if ((*src_stack)->next == *src_stack)										// Only one node in src_stack
        *src_stack = NULL;
	else 
	{																			// More than one node in src_stack
        (*src_stack)->prev->next = (*src_stack)->next;
        (*src_stack)->next->prev = (*src_stack)->prev;
        *src_stack = (*src_stack)->next;
    }																			// Add node to destination stack
    if (*dest_stack == NULL) 
	{																			// Destination stack is empty
		*dest_stack = node_to_move;
        node_to_move->next = node_to_move;
        node_to_move->prev = node_to_move;
    }
	else 
	{																			// Destination stack is not empty
        node_to_move->next = *dest_stack;
        node_to_move->prev = (*dest_stack)->prev;
        (*dest_stack)->prev->next = node_to_move;
        (*dest_stack)->prev = node_to_move;
        *dest_stack = node_to_move; 											// New node becomes the head
    }
    	printf("p%c\n", direction); 											// Print the command
}
/*
- Swap the top two elements of stack.
*/
void	swap(char stack_name, t_list **stack) 
{
	if (*stack == NULL || (*stack)->next == *stack) 
		return;

	t_list *first = *stack;
	t_list *second = (*stack)->next;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;

	if (first->next != NULL) 
		first->next->prev = first;
	if (second->prev != NULL) 
		second->prev->next = second;
	*stack = second;
	printf("s%c\n", stack_name); 													// Print the command for the checker
}
/*
- Swap the top two elements of both stacks.
*/
void	swap_both(t_list **stack_a, t_list **stack_b)
{
	int i;
	i = 2;
	t_list **stack;
	stack = stack_a;
	while(i--)
	{
		if (*stack == NULL || (*stack)->next == *stack) 
			return;
		t_list *first = *stack;
		t_list *second = (*stack)->next;

		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		if (first->next != NULL) 
			first->next->prev = first;
		if (second->prev != NULL) 
			second->prev->next = second;
		*stack = second;
		stack = stack_b; 															// Switch to stack_b
	}
    printf("ss\n"); 																// Print the command for the checker
}
/*
- Rotate the top two elements of stack.
*/
void rotate_both(char *direction, t_list **stack_a, t_list **stack_b) 
{
    int i = 2;
    t_list **stack = stack_a; 														// Start with stack_a

    while (i--) 
	{
        if (*stack == NULL || (*stack)->next == *stack)
			return;
        t_list *head = *stack;
        t_list *tail = (*stack)->prev;

        if (ft_strncmp(direction, "r", sizeof("r")) == 0) 							// Rotate up (head to tail)
            *stack = head->next;
        else if (ft_strncmp(direction, "rr", sizeof("rr")) == 0) 					// Rotate down (tail to head)
            *stack = tail;
		stack = stack_b;
    }
	printf("%s\n", direction); 														// Print the command for the checker
}

//##############################################################################
// SORTING ALGORITHMS
//##############################################################################
// will loock for the min and rotate the stack until it is at the top and then push it to the other stack
void heuristic_algo_sort(t_list **stack_a, t_list **stack_b, int size)
{
    int pos;
	t_list *min_node;
	t_list *current;

    for (int i = 0; i < size; i++) 
	{
        pos = 0;
		min_node = find_min_node(*stack_a);
        current = *stack_a;
        while (current != min_node)
		{
            pos++;
            current = current->next;
        }
        while ((*stack_a) != min_node) 
		{
            if (pos < size / 2)
                rotate("r", 'a', stack_a);
			else 
                rotate("rr", 'a', stack_a);
        }
        push('b', stack_a, stack_b);
    }
    while (*stack_b)
        push('a', stack_a, stack_b);
}

int calculate_max_bits(int size) {
    int max_bits = 0;
    int max_index = size - 1; 
    while (max_index > 0) {
        max_index >>= 1;
        max_bits++;
    }
    return max_bits;
}

void radix_sort1(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	int		j;
	int		bit;
	t_list	*node;

	i = 0;
	while (i < 10)   															//max_bits=(9digits/32-bit/4 bytes for int, but whe made the index, so it will be max 3 digits/10 bits/2 bytes)
	{
		j = 0;
		while (j++ < size)
		{
			node = *stack_a;
			bit = (node->index >> i) & 1;
			if (bit == 1)
			{
				rotate("r", 'a', stack_a);
			}
			else
			{
				push('b', stack_a, stack_b);
			}
		}
		while (ft_lstsize(*stack_b) > 0)
			push('a', stack_a, stack_b);
		i++;
	}
}
int digits_to_bits(int digits) {
  if (digits <= 0) {
    return 0; // Handle invalid input
  }

  int bits = 0;
  int max_value = 1; 

  while (max_value < digits) 
  {
    max_value *= 2; 
    bits++;
  }

  return (bits + 1);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	max_bits = digits_to_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
			{
				rotate("r", 'a', stack_a);
			}
			else
			{
				push('b', stack_a, stack_b);
			}
		}
		while (ft_lstsize(*stack_b) != 0)
			push('a', stack_a, stack_b);
		i++;
	}
																
}
t_list *sort_stack(t_list *stack_a1, t_list *stack_b1)
{
	t_list **stack_a;
	t_list **stack_b;
	int stack_a_size;

	stack_a = &stack_a1;
	stack_b = &stack_b1;
	stack_a_size = ft_lstsize(stack_a1);
	if (stack_a_size <= 5)
		heuristic_algo_sort(stack_a, stack_b, stack_a_size);
	else
		radix_sort(stack_a, stack_b, stack_a_size);
	return(*stack_a);
}

//##############################################################################
// MAIN
//##############################################################################
int	main(int argc, char **argv)
{
	t_list *stack_a;
    t_list *stack_b;
																				/* Check Inputs*/
	argv = check_args_1(argc, argv);
	stack_a = array_to_d_linked_list(argv);
	stack_b = NULL;
																				/* "Pre Sorting" Input(Selection Sort(get min)) and 
			adding the Indexing in the Linked List*/
	add_index_numbers(stack_a);
																				/* Sorting the Stack */
	stack_a=sort_stack(stack_a, stack_b);
																				/* Free Memmory Allocated */
	return (0);
}

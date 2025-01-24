
void	ft_swap_pointers(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
//##############################################################################
// UTILS/LINKED LIST MANIPULATION
//##############################################################################
/*
- Create a new node for the circular doubly linked list
*/

t_list	*ft_lstnew(int value, int index)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		write(1, "Error\n", 6);
		halt_exit_(1);
	}
	new_node->value = value;
	new_node->index = index;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

/*
Add a node to the end of a circular doubly linked list
*/
void	ft_lstadd_back(t_list **stack, t_list *new_node)
{
	t_list	*tail;

	if (!*stack)
	{
		*stack = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = tail;
		tail->next = new_node;
		(*stack)->prev = new_node;
	}
}

/*
Get the size of a circular doubly linked list
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	if (!lst)
		return (0);
	i = 1;
	current = lst;
	while (current->next != lst)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/*
Free the circular doubly linked list
*/
void	ft_free_list(t_list *stack)
{
	t_list	*current;
	t_list	*temp;

	if (stack == NULL)
		return ;
	current = stack->next;
	if (current != stack)
	{
		while (current != stack)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
	}
	free(stack);
}

/*
Find the minimum value node in a circular linked list 
	(excluding a given index)
*/
t_list	*find_min_node(t_list *stack)
{
	t_list	*min_node;
	t_list	*current;
	int		first_iteration;

	min_node = NULL;
	current = stack;
	first_iteration = 1;
	if (!stack)
		return (NULL);
	while (first_iteration || current != stack)
	{
		if (min_node == NULL || current->value < min_node->value)
		{
			min_node = current;
		}
		current = current->next;
		first_iteration = 0;
	}
	return (min_node);
}

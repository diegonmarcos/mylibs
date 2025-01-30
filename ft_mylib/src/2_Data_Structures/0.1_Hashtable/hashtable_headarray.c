/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_headarray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:43:05 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/30 19:44:23 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

/*
typedef struct s_hashnode
{
	char				*key;
	int					value;
	struct s_hashnode	*next;
}						t_hashnode;
*/
unsigned int	hash(const char *key, int size)
{
	unsigned int	hash;
	int				c;

	hash = 5381;
	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;
	return (hash % size);
}

t_hashnode	*create_node(const char *key, int value)
{
	t_hashnode	*new_node;

	new_node = (t_hashnode *)malloc(sizeof(t_hashnode));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed for node\n");
		return (NULL);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed for key\n");
		free(new_node);
		return (NULL);
	}
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	insert(t_hashnode **table, int size, const char *key, int value)
{
	unsigned int	index;
	t_hashnode		*new_node;

	index = hash(key, size);
	new_node = create_node(key, value);
	if (new_node == NULL)
		return ;
	if (table[index] == NULL)
		table[index] = new_node;
	else
	{
		new_node->next = table[index];
		table[index] = new_node;
	}
}

int	get(t_hashnode **table, int size, const char *key)
{
	unsigned int	index;
	t_hashnode		*current;

	index = hash(key, size);
	current = table[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (-1);
}

void	free_hashtable(t_hashnode **table, int size)
{
	int			i;
	t_hashnode	*current;
	t_hashnode	*temp;

	if (table == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		current = table[i];
		while (current != NULL)
		{
			temp = current;
			current = current->next;
			free(temp->key);
			free(temp);
		}
		i++;
	}
	free(table);
}

int	main(void)
{
	int			size;
	t_hashnode	**table;

	size = 10;
	table = (t_hashnode **)calloc(size, sizeof(t_hashnode *));
	if (table == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed for hash table array\n");
		return (1);
	}
	insert(table, size, "apple", 1);
	insert(table, size, "banana", 2);
	insert(table, size, "cherry", 3);
	insert(table, size, "date", 4);
	insert(table, size, "e", 5);
	printf("Value of apple: %d\n", get(table, size, "apple"));
	printf("Value of banana: %d\n", get(table, size, "banana"));
	printf("Value of cherry: %d\n", get(table, size, "cherry"));
	printf("Value of date: %d\n", get(table, size, "date"));
	printf("Value of e: %d\n", get(table, size, "e"));
	printf("Value of grape: %d\n", get(table, size, "grape"));
	free_hashtable(table, size);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_db.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:10:08 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/27 20:10:23 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

// Assuming a linked list structure like this
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

// ############################################################################
// DEBBUGING PRINTERS & LOGGERS
// ############################################################################
void	print_linkedlist_debbuging(t_node *head, int iterator)
{
	FILE	*output_file;
	t_node	*current;

	output_file = fopen("debbuging.txt", "a"); // Open file in append mode
	if (output_file == NULL)
	{
		perror("Error opening output file");
		return ;
	}
	fprintf(output_file, "--------------------\n");
	fprintf(output_file, "Iteration: %d\n", iterator);
	fprintf(output_file, "Linked List Values:\n");
	current = head;
	while (current != NULL)
	{
		fprintf(output_file, "%d ", current->data);
		current = current->next;
	}
	fprintf(output_file, "\n");
	fprintf(output_file, "--------------------\n\n");
	fclose(output_file);
}

void	print_array_debbugging(int *arr, int size, int iterator)
{
	FILE	*output_file;
	int		i;

	output_file = fopen("debbuging.txt", "a"); // Open file in append mode
	if (output_file == NULL)
	{
		perror("Error opening output file");
		return ;
	}
	fprintf(output_file, "--------------------\n");
	fprintf(output_file, "Iteration: %d\n", iterator);
	fprintf(output_file, "Array:\n");
	i = 0;
	while (i < size)
	{
		fprintf(output_file, "%d ", arr[i]);
		i++;
	}
	fprintf(output_file, "\n");
	fprintf(output_file, "--------------------\n\n");
	fclose(output_file);
}

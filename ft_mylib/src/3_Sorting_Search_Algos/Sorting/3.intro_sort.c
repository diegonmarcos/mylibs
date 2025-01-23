/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.intro_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:34:07 by dinepomu          #+#    #+#             */
/*   Updated: 2025/01/23 13:41:13 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
This is the implementation of intro sort algorithm. It is a hybrid sorting 
	algorithm that provides both fast average performance and optimal worst-case
	performance. It begins with quicksort and switches to heapsort when the 
	recursion depth exceeds a level based on the number of elements being sorted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	swap(int *a, int *b)
{
	int	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot = arr[high];
	int	i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	heapify(int arr[], int n, int i)
{
	int	largest = i;
	int	l = 2 * i + 1;
	int	r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void	heap_sort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void	quick_sort(int arr[], int low, int high, int depthLimit)
{
	if (low < high)
	{
		if (depthLimit == 0)
		{
			heap_sort(arr + low, high - low + 1);
			return ;
		}
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1, depthLimit - 1);
		quick_sort(arr, pi + 1, high, depthLimit - 1);
	}
}

void	intro_sort(int arr[], int n)
{
	int	depthLimit = 2 * log(n);
	quick_sort(arr, 0, n - 1, depthLimit);
}

int	main(void)
{
	int	arr[] = {10, 7, 8, 9, 1, 5};
	int	n = sizeof(arr) / sizeof(arr[0]);

	intro_sort(arr, n);
	printf("Sorted array: \n");
	for (int i = 0; i < n; i++) 
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


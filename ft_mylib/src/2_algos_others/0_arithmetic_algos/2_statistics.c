/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_statistics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:14:35 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 17:00:08 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_mylib.h"

long	ft_max(long a, long b)
{
	if (a > b)
		return(a);
	return(b);
}

long	ft_min(long a, long b)
{
	if (a < b)
		return(a);
	return(b);
}

long	ft_median(long *array, long size)
{
	long	median;
	long	*array_sorted;
	long	i;

	array_sorted = ft_calloc(size, sizeof(long));
	ft_memcpy(array_sorted, array, size * sizeof(long));
	ft_sort(array_sorted, size);
	if (size % 2 == 0)
		median = (array_sorted[size / 2] + array_sorted[size / 2 - 1]) / 2;
	else
		median = array_sorted[size / 2];
	free(array_sorted);
	return (median);
}

long	ft_mean(long *array, long size)
{
	long	mean;
	long	sum;
	long	i;

	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += array[i];
		i++;
	}
	mean = sum / size;
	return (mean);
}

long	ft_mode(long *array, long size)
{
	long	mode;
	long	*array_sorted;
	long	i;
	long	j;
	long	count;
	long	max_count;

	array_sorted = ft_calloc(size, sizeof(long));
	ft_memcpy(array_sorted, array, size * sizeof(long));
	ft_sort(array_sorted, size);
	i = 0;
	mode = array_sorted[0];
	max_count = 1;
	while (i < size)
	{
		count = 1;
		j = i + 1;
		while (j < size && array_sorted[j] == array_sorted[i])
		{
			count++;
			j++;
		}
		if (count > max_count)
		{
			mode = array_sorted[i];
			max_count = count;
		}
		i = j;
	}
	free(array_sorted);
	return (mode);
}

long	ft_range(long *array, long size)
{
	long	range;
	long	*array_sorted;

	array_sorted = ft_calloc(size, sizeof(long));
	ft_memcpy(array_sorted, array, size * sizeof(long));
	ft_sort(array_sorted, size);
	range = array_sorted[size - 1] - array_sorted[0];
	free(array_sorted);
	return (range);
}

long	ft_variance(long *array, long size)
{
	long	variance;
	long	mean;
	long	sum;
	long	i;

	mean = ft_mean(array, size);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_pow(array[i] - mean, 2);
		i++;
	}
	variance = sum / size;
	return (variance);
}

long	ft_standard_deviation(long *array, long size)
{
	long	standard_deviation;
	long	variance;

	variance = ft_variance(array, size);
	standard_deviation = ft_sqrt(variance);
	return (standard_deviation);
}

long	ft_quartile(long *array, long size, long quartile)
{
	long	quartile_value;
	long	*array_sorted;
	long	i;

	array_sorted = ft_calloc(size, sizeof(long));
	ft_memcpy(array_sorted, array, size * sizeof(long));
	ft_sort(array_sorted, size);
	if (quartile == 1)
		quartile_value = array_sorted[size / 4];
	else if (quartile == 2)
		quartile_value = array_sorted[size / 2];
	else if (quartile == 3)
		quartile_value = array_sorted[size * 3 / 4];
	free(array_sorted);
	return (quartile_value);
}

long	ft_iqr(long *array, long size)
{
	long	iqr;
	long	q1;
	long	q3;

	q1 = ft_quartile(array, size, 1);
	q3 = ft_quartile(array, size, 3);
	iqr = q3 - q1;
	return (iqr);
}

long	ft_skewness(long *array, long size)
{
	long	skewness;
	long	mean;
	long	standard_deviation;
	long	sum;
	long	i;

	mean = ft_mean(array, size);
	standard_deviation = ft_standard_deviation(array, size);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_pow(array[i] - mean, 3);
		i++;
	}
	skewness = sum / (size * ft_pow(standard_deviation, 3));
	return (skewness);
}

long	ft_kurtosis(long *array, long size)
{
	long	kurtosis;
	long	mean;
	long	standard_deviation;
	long	sum;
	long	i;

	mean = ft_mean(array, size);
	standard_deviation = ft_standard_deviation(array, size);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += ft_pow(array[i] - mean, 4);
		i++;
	}
	kurtosis = sum / (size * ft_pow(standard_deviation, 4));
	return (kurtosis);
}

long	ft_covariance(long *array1, long *array2, long size)
{
	long	covariance;
	long	mean1;
	long	mean2;
	long	sum;
	long	i;

	mean1 = ft_mean(array1, size);
	mean2 = ft_mean(array2, size);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += (array1[i] - mean1) * (array2[i] - mean2);
		i++;
	}
	covariance = sum / size;
	return (covariance);
}

long	ft_correlation(long *array1, long *array2, long size)
{
	long	correlation;
	long	covariance;
	long	standard_deviation1;
	long	standard_deviation2;

	covariance = ft_covariance(array1, array2, size);
	standard_deviation1 = ft_standard_deviation(array1, size);
	standard_deviation2 = ft_standard_deviation(array2, size);
	correlation = covariance / (standard_deviation1 * standard_deviation2);
	return (correlation);
}

long	ft_z_score(long value, long *array, long size)
{
	long	z_score;
	long	mean;
	long	standard_deviation;

	mean = ft_mean(array, size);
	standard_deviation = ft_standard_deviation(array, size);
	z_score = (value - mean) / standard_deviation;
	return (z_score);
}


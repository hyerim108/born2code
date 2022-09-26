/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:58:26 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/26 19:07:40 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int arr[], int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*copy_arr(t_stack *init, int size, int flag)
{
	int	*arr;
	int	idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	idx = -1;
	if (flag == 1)
	{
		while (++idx < size)
			arr[idx] = init->a[init->size_a - idx];
	}
	else
	{
		while (++idx < size)
			arr[idx] = init->b[init->size_b - idx];
	}
	return (arr);
}

void	get_pivot(t_stack *init, int size, int x)
{
	int			*arr;
	int			pivot;

	arr = copy_arr(init, size, x);
	ft_sort(arr, size);
	pivot = size / 4;
	if (x == 1)
	{
		init->pivot1 = arr[size - pivot];
		init->pivot2 = arr[size - pivot * 2];
	}
	else
	{
		init->pivot1 = arr[pivot * 2 - 1];
		init->pivot2 = arr[pivot - 1];
	}
	free(arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:43:33 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 11:22:29 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	check_a(t_stack *init, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->stack_a[i] < init->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_b(t_stack *init, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->stack_b[i] < init->stack_b[i - 1])
			return (0);
		i++;
	}
	return (1);
}

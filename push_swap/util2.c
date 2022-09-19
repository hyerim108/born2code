/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:17:46 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 19:27:25 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	factor_split(int ac, char **av)
{
	int		index;
	int		size;
	int		check;
	char	**split_data;

	size = 0;
	index = 1;
	while (index < ac)
	{
		check = 0;
		while (av[index][check])
		{
			if (!ft_isspace(av[index][check]))
				break;
			check++;
		}
		split_data = ft_split(av[index], ' ');
		size += get_length(split_data);
		index++;
	}
	return (size);
}

void setting_pivot(t_stack *init, int size, int f)
{
	int		*arr;
	int		mid;
	
    arr = c_paste(init, size, f);
	sort_array(arr, size);
	mid = size / 3;
	init->pivot1 = arr[size - mid];
	init->pivot2 = arr[size - mid * 2];
	free(arr);
}

int	*c_paste(t_stack *init, int size, int f)
{
	int *arr;
	int j;

	arr = malloc(sizeof(int) * size);
	j = 0;
	while (size > 0)
	{
		arr[j] = init->stack_a[init->size_a - size];
		size--;
		j++;
	}
	return (arr);
}

void	b_send(t_stack *init, int size, t_append *c)
{
	int	i;

	i = 0;
	printf("pivot 1 %d\n", init->pivot1);
	printf("pivot 2 %d\n", init->pivot2);
	while (i < size)
	{
		if (init->stack_a[init->size_a] >= init->pivot1)
		{
			// printf("ra %d\n", init->stack_a[init->size_a]);
			ra(init);
			c->ra++;
		}
		else
		{
			pb(init);
			c->pb++;
			if (init->stack_b[init->size_b] >= init->pivot2)
			{
				// printf("ra %d\n", init->stack_b[init->size_b]);
				rb(init);
				c->rb++;
			}
		}
		i++;
	}
}

void			sort_array(int *arr, int size)
{
	int i;
	int j;
	int tmp;

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
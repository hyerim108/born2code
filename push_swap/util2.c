/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:17:46 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/18 19:20:45 by hyerimki         ###   ########.fr       */
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
	init->pivot1 = arr[size / 2];
	init->pivot2 = arr[size];
}

int	*c_paste(t_stack *init, int size, int f)
{
	int *arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 1;
	while (i < size + 1)
	{
		arr[i] = init->stack_a[init->size_a - i];
		i++;
	}
	return (arr);
}

void	b_send(t_stack *init, int size, t_append *c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->stack_a[init->size_a] >= init->pivot1)
		{
			printf("%d\n", init->pivot1);
			c->ra++;
		}
		else
		{
			c->pb++;
			if (init->stack_b[init->size_b] >= init->pivot2)
			{
				printf("%d\n", init->pivot2);
				c->rb++;
				printf("%d\n", c->rb);
			}
		}
		i++;
	}
}
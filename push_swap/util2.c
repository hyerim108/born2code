/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:17:46 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 19:02:31 by hyerimki         ###   ########.fr       */
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
				break ;
			check++;
		}
		split_data = ft_split(av[index], ' ');
		size += get_length(split_data);
		index++;
	}
	ft_free(split_data);
	return (size);
}

void	setting_pivot(t_stack *init, int size, int f)
{
	int		*arr;
	int		mid;

	arr = c_paste(init, size, f);
	sort_array(arr, size);
	mid = size / 3;
	if (mid % 3 == 2)
		mid++;
	if (f == 1)
	{
		init->pivot1 = arr[size - mid];
		init->pivot2 = arr[size - mid * 2];
	}
	else
	{
		init->pivot1 = arr[mid * 2 - 1];
		init->pivot2 = arr[mid - 1];
	}
	free(arr);
}

int	*c_paste(t_stack *init, int size, int f)
{
	int	*arr;
	int	j;

	arr = malloc(sizeof(int) * size);
	j = -1;
	if (!arr)
		exit(1);
	if (f == 1)
	{
		while (++j < size)
			arr[j] = init->stack_a[init->size_a - j];
	}
	else
	{
		while (++j < size)
			arr[j] = init->stack_b[init->size_b - j];
	}
	return (arr);
}

void	b_send_u(t_stack *init, int size, t_append *c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->stack_a[init->size_a] >= init->pivot1)
		{
			ra(init, 1);
			c->ra+=1;
		}
		else
		{
			pb(init);
			c->pb+=1;
			if (init->stack_b[init->size_b] >= init->pivot2)
			{
				rb(init, 1);
				c->rb+=1;
			}
		}
		i++;
	}
}

void	a_send_u(t_stack *init, int size, t_append *c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->stack_b[init->size_b] <= init->pivot2)
		{
			rb(init, 1);
			c->ra+=1;
		}
		else
		{
			pa(init);
			c->pa+=1;
			if (init->stack_a[init->size_a] <= init->pivot1)
			{
				ra(init, 1);
				c->ra+=1;
			}
		}
		i++;
	}
}

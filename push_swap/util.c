/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:14 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/18 17:06:14 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setting(t_stack *init, int ac, char **av)
{
	int	size;

	size = factor_split(ac, av);
	initialization_stack(init, size);
	checking(init, ac, av, size);
}

int	double_check(int *arr, int idx, int num)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (arr[i] == num)
			return (0);
		i++;
	}
	return (1);
}

void	checking(t_stack *init, int ac, char **av, int size)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i++], ' ');
		j = 0;
		while (arr[j])
		{
			if (!ft_atoi2(arr[j], &init->stack_a[init->size_a]) || \
					!double_check(init->stack_a, init->size_a, init->stack_a[init->size_a]))
				print_error(-1);
			init->size_a += 1;
			j++;
		}
	}
}

void	initialization_stack(t_stack *init, int size)
{
	init->stack_a = malloc(sizeof(t_stack) * size);
	init->size_a = 0;
	init->stack_b = malloc(sizeof(t_stack) * size);
	init->size_b = 0;
	init->size = size;
}

int	check_sort(t_stack *init, int size)
{
	int	i;
	
	i = 0;
	while (i < init->size_a)
	{
		if (init->stack_a[i] < init->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

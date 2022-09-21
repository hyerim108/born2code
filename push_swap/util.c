/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:09:14 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 19:07:12 by hyerimki         ###   ########.fr       */
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

void	initialization_stack(t_stack *init, int size)
{
	init->stack_a = malloc(sizeof(int) * size);
	init->size_a = -1;
	init->stack_b = malloc(sizeof(int) * size);
	init->size_b = -1;
	init->size = size;
	if (!init->stack_a || !init->stack_b)
		exit(1);
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
	int		idx;
	int		tmp_idx;
	char	**tmp;
	int i;

	i = 1;
	while (i < ac)
	{
		tmp_idx = 0;
		tmp = ft_split(av[i++], ' ');
		while (tmp[tmp_idx])
		{
			init->size_a += 1;
			if (!ft_atoi(tmp[tmp_idx++], &init->stack_a[init->size_a]) || \
				!double_check(init->stack_a, init->size_a, init->stack_a[init->size_a]))
				print_error(-1);
		}
		ft_free(tmp);
	}
	swap_stack(init);
}

void			swap_stack(t_stack *init)
{
	int left;
	int right;
	int x;

	left = 0;
	right = init->size_a;
	while (left < right)
	{
		x = init->stack_a[left];
		init->stack_a[left] = init->stack_a[right];
		init->stack_a[right] = x;
		left++;
		right--;
	}
}
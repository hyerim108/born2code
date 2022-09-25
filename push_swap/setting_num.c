/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:09 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/25 16:00:24 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialization_stack(t_stack *init, int size)
{
	init->a = malloc(sizeof(int) * size);
	init->size_a = -1;
	init->b = malloc(sizeof(int) * size);
	init->size_b = -1;
	init->size = size;
	if (!init->a || !init->b)
		exit(1);
}

int		check_duplicate(int *arr, int size, int num)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (arr[idx] == num)
			return (0);
		idx++;
	}
	return (1);
}

void	setting_num(t_stack *init, char *argv[], int argc)
{
	int		idx;
	int		tmp_idx;
	char	**tmp;

	idx = 1;
	while (idx < argc)
	{
		tmp_idx = 0;
		tmp = ft_split(argv[idx++], ' ');
		while (tmp[tmp_idx])
		{
			init->size_a += 1;
			if (!ft_atoi(tmp[tmp_idx++], &init->a[init->size_a]) ||
				!check_duplicate(init->a, init->size_a, init->a[init->size_a]))
				print_error();
		}
		ft_free(tmp);
	}
	swap_stack(init);
}

void	swap_stack(t_stack *init)
{
	int l;
	int r;
	int temp;

	l = 0;
	r = init->size_a;
	while (l < r)
	{
		temp = init->a[l];
		init->a[l] = init->a[r];
		init->a[r] = temp;
		l++;
		r--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:17:46 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/25 14:39:54 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a_sort(t_stack *init, int size)
{
	int i;

	i = 0;
	while (i < init->size_a)
	{
		if (init->a[i] < init->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_b_sort(t_stack *init, int size)
{
	int i;

	i = 0;
	while (i < init->size_b)
	{
		if (init->b[i] > init->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	atob(t_stack *init, int size)
{
	t_count		cnt;
	int			idx;

	cnt = (t_count){0, 0, 0, 0};
	if (check_a_sort(init, size))
		return ;
	if (size <= 4)
	{
		twothreefour(init, size);
		return ;
	}
	get_pivot(init, size, 1);
	atob_util(init, &cnt, size);
	idx = -1;
	while (++idx < cnt.ra)
		rrr(init);
	atob(init, cnt.ra);
	btoa(init, cnt.rb);
	btoa(init, cnt.pb - cnt.rb);
}

void	btoa(t_stack *init, int size)
{
	t_count		cnt;
	int			idx;

	cnt = (t_count){0, 0, 0, 0};
	if (check_b_sort(init, size))
	{
		while (size--)
			pa(init);
		return ;
	}
	if (size <= 3)
	{
		onetwothree(init, size);
		return ;
	}
	get_pivot(init, size, 0);
	btoa_util(init, &cnt, size);
	atob(init, cnt.pa - cnt.ra);
	idx = -1;
	while (++idx < cnt.ra)
		rrr(init);
	atob(init, cnt.rb);
	btoa(init, cnt.ra);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 16:32:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	send_b(t_stack *init, int size)
{
	t_append	count;
	
	count = (t_append){0, 0, 0, 0};
	setting_pivot(init, size, 1);
	b_send(init, size, &count);
	
	return (0);
}

void	push_swap(int ac, char **av)
{
	t_stack		init;
	
	setting(&init, ac, av);
	if (!check_sort(&init, init.size))
	{
		send_b(&init, init.size);
	}
	else
		print_error(1);
}

void	sa(t_info *info, int flag)
{
	int tmp;

	if (info->a_top >= 1)
	{
		tmp = info->a[info->a_top];
		info->a[info->a_top] = info->a[info->a_top - 1];
		info->a[info->a_top - 1] = tmp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_info *info, int flag)
{
	int tmp;

	if (info->b_top >= 1)
	{
		tmp = info->b[info->b_top];
		info->b[info->b_top] = info->b[info->b_top - 1];
		info->b[info->b_top - 1] = tmp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void	rra(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->a[0];
	while (idx < info->a_top)
	{
		info->a[idx] = info->a[idx + 1];
		idx++;
	}
	info->a[info->a_top] = tmp;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->b[0];
	while (idx < info->b_top)
	{
		info->b[idx] = info->b[idx + 1];
		idx++;
	}
	info->b[info->b_top] = tmp;
	if (flag)
		write(1, "rrb\n", 4);
}
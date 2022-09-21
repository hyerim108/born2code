/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:30 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 16:29:05 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *init)
{
	if (init->size_a >= 0)
	{
		init->size_b+=1;
		init->stack_b[init->size_b] = init->stack_a[init->size_a];
		init->size_a-=1;
		write(1, "pb\n", 3);
	}
}

void	pa(t_stack *init)
{
	if (init->size_b >= 0)
	{
		init->size_a+=1;
		init->stack_a[init->size_a] = init->stack_b[init->size_b];
		init->size_b-=1;
		write(1, "pa\n", 3);
	}
}

void	sa(t_stack *init, int trues)
{
	int	x;

	if (init->size_a >= 1)
	{
		x = init->stack_a[init->size_a];
		init->stack_a[init->size_a] = init->stack_a[init->size_a - 1];
		init->stack_a[init->size_a - 1] = x;
	}
	if (trues)
		write(1, "sa\n", 3);
}

void	sb(t_stack *init, int trues)
{
	int	x;

	if (init->size_b >= 1)
	{
		x = init->stack_b[init->size_b];
		init->stack_b[init->size_b] = init->stack_b[init->size_b - 1];
		init->stack_b[init->size_b - 1] = x;
	}
	if (trues)
		write(1, "sb\n", 3);
}

void	ss(t_stack *init)
{
	sa(init, 0);
	sb(init, 0);
	write(1, "ss\n", 3);
}

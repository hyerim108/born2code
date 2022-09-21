/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 18:51:18 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *init, int trues)
{
	int	i;
	int	x;

	i = init->size_a;
	x = init->stack_a[init->size_a];
	if (i != -1)
	{
		while (i > 0)
		{
			init->stack_a[i] = init->stack_a[i - 1];
			i--;
		}
		init->stack_a[0] = x;
	}
	if (trues)
			write(1, "ra\n", 3);
}

void	rb(t_stack *init, int trues)
{
	int	i;
	int	x;

	i = init->size_b;
	x = init->stack_b[init->size_b];
	if (i != -1)
	{
		while (i > 0)
		{
			init->stack_b[i] = init->stack_b[i - 1];
			i--;
		}
		init->stack_b[0] = x;
	}
	if (trues)
		write(1, "rb\n", 3);
}

void	rr(t_stack *init)
{
	ra(init, 0);
	rb(init, 0);
	write(1, "rr\n", 3);
}

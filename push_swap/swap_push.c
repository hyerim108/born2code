/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:18:11 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/26 13:19:33 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *init, int x)
{
	int	temp;

	if (init->size_a >= 1)
	{
		temp = init->a[init->size_a];
		init->a[init->size_a] = init->a[init->size_a - 1];
		init->a[init->size_a - 1] = temp;
	}
	if (x)
		write(1, "sa\n", 3);
}

void	sb(t_stack *init, int x)
{
	int	temp;

	if (init->size_b >= 1)
	{
		temp = init->b[init->size_b];
		init->b[init->size_b] = init->b[init->size_b - 1];
		init->b[init->size_b - 1] = temp;
	}
	if (x)
		write(1, "sb\n", 3);
}

void	ss(t_stack *init)
{
	sa(init, 0);
	sb(init, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack *init)
{
	if (init->size_b >= 0)
	{
		init->size_a += 1;
		init->a[init->size_a] = init->b[init->size_b];
		init->size_b -= 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *init)
{
	if (init->size_a >= 0)
	{
		init->size_b += 1;
		init->b[init->size_b] = init->a[init->size_a];
		init->size_a -= 1;
		write(1, "pb\n", 3);
	}
}

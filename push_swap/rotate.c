/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/25 15:04:06 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *init, int x)
{
	int temp;
	int i;

	i = init->size_a;
	if (i != -1)
	{
		temp = init->a[init->size_a];
		while (i > 0)
		{
			init->a[i] = init->a[i - 1];
			i--;
		}
		init->a[0] = temp;
	}
	if (x)
		write(1, "ra\n", 3);
}

void	rb(t_stack *init, int x)
{
	int temp;
	int i;

	i = init->size_b;
	if (i != -1)
	{
		temp = init->b[init->size_b];
		while (i > 0)
		{
			init->b[i] = init->b[i - 1];
			i--;
		}
		init->b[0] = temp;
	}
	if (x)
		write(1, "rb\n", 3);
}

void	rr(t_stack *init)
{
	ra(init, 0);
	rb(init, 0);
	write(1, "rr\n", 3);
}

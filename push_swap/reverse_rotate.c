/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/26 13:08:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *init, int x)
{
	int	temp;
	int	i;

	i = 0;
	temp = init->a[0];
	while (i < init->size_a)
	{
		init->a[i] = init->a[i + 1];
		i++;
	}
	init->a[init->size_a] = temp;
	if (x)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *init, int x)
{
	int	temp;
	int	i;

	i = 0;
	temp = init->b[0];
	while (i < init->size_b)
	{
		init->b[i] = init->b[i + 1];
		i++;
	}
	init->b[init->size_b] = temp;
	if (x)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *init)
{
	rra(init, 0);
	rrb(init, 0);
	write(1, "rrr\n", 4);
}

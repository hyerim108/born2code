/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:31:07 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/25 14:41:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twothreefour(t_stack *init, int size)
{
	if (size == 2 || size == 3)
	{
		if (init->a[init->size_a] > init->a[init->size_a - 1])
			sa(init, 1);
		if (size == 3)
		{
			if (init->a[init->size_a - 1] > init->a[init->size_a - 2])
			{
				ra(init, 1);
				sa(init, 1);
				rra(init, 1);
				if (init->a[init->size_a] > init->a[init->size_a - 1])
					sa(init, 1);
			}
		}
	}
	if (size == 4)
		argment_sa(init);
}

void	onetwothree(t_stack *init, int size)
{
	if (size >= 1 && size <= 3)
		pa(init);
	if (size == 2 || size == 3)
	{
		pa(init);
		if (init->a[init->size_a] > init->a[init->size_a - 1])
			sa(init, 1);
		if (size == 3)
		{
			pa(init);
			if (init->a[init->size_a] > init->a[init->size_a - 1])
				sa(init, 1);
			if (init->a[init->size_a - 1] > init->a[init->size_a - 2])
			{
				ra(init, 1);
				sa(init, 1);
				rra(init, 1);
				if (init->a[init->size_a] > init->a[init->size_a - 1])
					sa(init, 1);
			}
		}
	}
}

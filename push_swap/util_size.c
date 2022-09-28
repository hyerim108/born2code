/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:35:36 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/28 13:05:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_3(t_stack *init)
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

void	size_a(t_stack *init, int size)
{
	if (size == 2 || size == 3)
	{
		if (init->a[init->size_a] > init->a[init->size_a - 1])
			sa(init, 1);
		if (size == 3)
			size_3(init);
	}
}

void	size_b(t_stack *init, int size)
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
			size_3(init);
		}
	}
}

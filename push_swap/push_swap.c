/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 11:52:09 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b(t_stack *init, int size)
{
	t_append	count;

	count = (t_append){0, 0, 0, 0};
	setting_pivot(init, size, 1);
	b_send_u(init, size, &count);
	send_sort(init, size, &count);
}

void	push_swap(int ac, char **av)
{
	t_stack		init;

	setting(&init, ac, av);
	if (!check_a(&init, init.size))
	{
		if (init.size_a == 2)
			argment_3(&init);
		else
			send_b(&init, init.size);
	}
	else
		print_error(1);
}

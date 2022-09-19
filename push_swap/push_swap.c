/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 17:55:07 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

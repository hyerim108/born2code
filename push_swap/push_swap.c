/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/22 15:38:21 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b(t_stack *init, int size)
{
	t_append	count;
	int			i;
	
	count = (t_append){0, 0, 0, 0};
	if (check_a(init, size))
		return ;
	if (size <= 4)
	{
		check_noga(init, size);
		return ;
	}
	setting_pivot(init, size, 1);
	clean_b(init, size, &count);
	send_b(init, count.ra);
	send_a(init, count.rb);
	send_a(init, count.pb - count.rb);
}

void    send_a(t_stack *init, int size)
{
	t_append	count;
	int			i;

	count = (t_append){0, 0, 0, 0};
	if (check_b(init, size))
		return ;
	if (size <= 3)
	{
		check_noga(init, size);
		return ;
	}
	setting_pivot(init, size, 0);
	clean_a(init, size, &count);
	send_a(init, count.rb);
}

void	push_swap(int ac, char **av)
{
	t_stack		init;
	
	setting(&init, ac, av);
	if (!check_a(&init, init.size))
	{
		if (init.size_a == 2 || init.size_a == 4)
			nogada(&init);
		else
			send_b(&init, init.size);
	}
	free(init.stack_a);
	free(init.stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:58:00 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/26 12:46:19 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nogada(t_stack *init)
{
	if (init->size_a == 2)
		argment_3(init);
	else if (init->size_a == 4)
		argument_5(init);
}

void	setting(t_stack *init, int ac, char **av)
{
	int	size;

	size = factor_split(ac, av);
	init_stack(init, size);
	setting_num(init, av, ac);
}

void	push_swap(int ac, char **av)
{
	t_stack	init;

	setting(&init, ac, av);
	if (!check_a_sort(&init, init.size))
	{
		if (init.size_a == 2 || init.size_a == 4)
			nogada(&init);
		else
			atob(&init, init.size);
	}
	free(init.a);
	free(init.b);
}

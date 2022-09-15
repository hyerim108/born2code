/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:04 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	atob(t_stack *init, int size)
{
	int	pivot;

	pivot = setting_pivot(init, size, 1);
}

void	push_swap(int ac, char **av)
{
	t_stack	init;

	setting(&init, ac, av);
	if (!check_sort(&init, init.size))
	{
		atob(&init, init.size);
		print_error(-1);
	}
	else
		print_error(1);
}

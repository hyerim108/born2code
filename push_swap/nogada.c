/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nogada.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 19:26:27 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    argment_3(t_stack *init)
{
    if (init->stack_a[2] > init->stack_a[1])
        sa(init, 1);
    if (init->stack_a[0] < init ->stack_a[1])
    {
        rra(init, 1);
        if (init->stack_a[1] < init->stack_a[2])
            sa(init, 1);
    }
}

void	argment_4(t_stack *init)
{
	int *arr;
	int idx;

	idx = -1;
	arr = c_paste(init, 5, 1);
	sort_array(arr, 5);
	while (++idx < 5)
	{
		if (arr[1] >= init->stack_a[init->size_a])
			pb(init);
		else
			ra(init, 1);
	}
	argment_3(init);
	if (init->stack_b[0] > init->stack_b[1])
		sb(init, 1);
	pa(init);
	pa(init);
	free(arr);
}
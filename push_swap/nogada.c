/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nogada.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/22 15:39:17 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nogada(t_stack *init)
{
	if (init->size_a == 2)
		argment_3(init);
	else if(init->size_a == 4)
		argment_5(init);
}

void	check_noga(t_stack *init, int size)
{
	if (size == 2 || size == 3)
	{
		if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
			sa(init, 1);
		// pa(init);
		// pa(init);
		// pa(init);
	}
	if (size == 4)
		argment_4(init);
}

void    argment_3(t_stack *init)
{
    if (init->stack_a[2] > init->stack_a[1])
        sa(init, 1);
    if (init->stack_a[0] < init->stack_a[1])
    {
        rra(init, 1);
        if (init->stack_a[1] < init->stack_a[2])
            sa(init, 1);
    }
}

void	argment_4(t_stack *init)
{
	if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
		sa(init, 1);
	pb(init);
	if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
		sa(init, 1);
	pb(init);
	if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1]
		&& init->stack_b[init->size_b] < init->stack_b[init->size_b - 1])
		ss(init);
	else if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
		sa(init, 1);
	else if (init->stack_b[init->size_b] < init->stack_b[init->size_b - 1])
		sb(init, 1);
	pa(init);
	if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
		sa(init, 1);
	pa(init);
	if (init->stack_a[init->size_a] > init->stack_a[init->size_a - 1])
		sa(init, 1);
}

void	argment_5(t_stack *init)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nogada.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/28 13:06:04 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argment_3(t_stack *init)
{
	if (init->a[2] > init->a[1] && init->a[1] > init->a[0] && \
			init->a[2] > init->a[0])
	{
		sa(init, 1);
		rra(init, 1);
	}
	else if (init->a[0] < init->a[1] && init->a[1] > init->a[2] && \
			init->a[0] > init->a[2])
	{
		rra(init, 1);
		sa(init, 1);
	}
	else if (init->a[0] > init->a[1] && init->a[1] < init->a[2] && \
			init->a[0] < init->a[2])
		ra(init, 1);
	else if (init->a[2] < init->a[1] && init->a[1] > init->a[0] && \
			init->a[0] < init->a[2])
		rra(init, 1);
	else if (init->a[0] > init->a[1] && init->a[1] < init->a[2] && \
			init->a[0] > init->a[2])
		sa(init, 1);
}

void	argument_5(t_stack *init)
{
	int	*arr;
	int	i;

	i = -1;
	arr = copy_arr(init, 5, 1);
	ft_sort(arr, 5);
	while (++i < 5)
	{
		if (arr[1] >= init->a[init->size_a])
			pb(init);
		else
			ra(init, 1);
	}
	argment_3(init);
	if (init->b[0] > init->b[1])
		sb(init, 1);
	pa(init);
	pa(init);
	free(arr);
}

void	btoa_util(t_stack *init, t_count *cnt, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->b[init->size_b] <= init->pivot2)
		{
			rb(init, 1);
			cnt->rb += 1;
		}
		else
		{
			pa(init);
			cnt->pa += 1;
			if (init->a[init->size_a] <= init->pivot1)
			{
				ra(init, 1);
				cnt->ra += 1;
			}
		}
		i++;
	}
}

void	atob_util(t_stack *init, t_count *cnt, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->a[init->size_a] >= init->pivot1)
		{
			ra(init, 1);
			cnt->ra += 1;
		}
		else
		{
			pb(init);
			cnt->pb += 1;
			if (init->b[init->size_b] >= init->pivot2)
			{
				rb(init, 1);
				cnt->rb += 1;
			}
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 19:29:53 by hyerimki         ###   ########.fr       */
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
}

void    send_a(t_stack *init, int size)
{
    t_append    count;
    int         i;
    
    count = (t_append){0, 0, 0, 0};
    if (check_b(init, size))
    {
        while (size--)
            pa(init);
        return ;
    }
}

void	push_swap(int ac, char **av)
{
	t_stack		init;
	
	setting(&init, ac, av);
	printf("%d\n", init.size_a);
	if (!check_a(&init, init.size))
	{
		if (init.size_a == 2)
			argment_3(&init);
		else if (init.size_a == 4)
			argment_4(&init);
		// else
			// send_b(&init, init.size);
	}
	free(init.stack_a);
	free(init.stack_b);
}

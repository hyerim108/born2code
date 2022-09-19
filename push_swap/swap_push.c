/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:30 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 17:52:06 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(t_stack *init)
{
    if (init->size_a >= 0)
    {
        init->size_b++;
        init->stack_b[init->size_b] = init->stack_a[init->size_a]; 
        init->size_a--;
        write(1, "pa\n", 3);
    }
}

void    pa(t_stack *init)
{
    if (init->size_b >= 0)
    {
        init->size_a++;
        init->stack_a[init->size_a] = init->stack_b[init->size_b]; 
        init->size_b--;
        write(1, "pa\n", 3);
    }
}

void    sa(t_stack *init)
{
    int x;
    
    if (init->size_a >= 1)
    {
        x = init->stack_a[init->size_a];
        init->stack_a[init->size_a] = init->stack_a[init->size_a - 1];
        init->stack_a[init->size_a - 1] = x;
    }
    write(1, "sa\n", 3);
}

void    sb(t_stack *init)
{
    int x;
    
    if (init->size_b >= 1)
    {
        x = init->stack_b[init->size_b];
        init->stack_b[init->size_b] = init->stack_b[init->size_b - 1];
        init->stack_b[init->size_b - 1] = x;
    }
    write(1, "sb\n", 3);
}

void    ss(t_stack *init)
{
    sa(init);
    sb(init);
    write(1, "ss\n", 3);
}
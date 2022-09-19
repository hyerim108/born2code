/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 17:54:20 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack *init)
{
    int i;
    int x;
    
    i = 0;
    x = init->stack_a[0];
    while (i < init->size_a)
    {
        init->stack_a[i] = init->stack_a[i + 1];
        i++;
    }
    init->stack_a[init->size_a] = x;
    write(1, "rra\n", 4);
}

void    rrb(t_stack *init)
{
    int i;
    int x;
    
    i = 0;
    x = init->stack_b[0];
    while (i < init->size_b)
    {
        init->stack_b[i] = init->stack_b[i + 1];
        i++;
    }
    init->stack_b[init->size_b] = x;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *init)
{
    rra(init);
    rrb(init);
    write(1, "rrr\n", 4);
}
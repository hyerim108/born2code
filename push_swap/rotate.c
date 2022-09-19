/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 16:16:22 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *init)
{
    int i;
    int x;
    
    i = init->size_a;
    x = init->stack_a[init->size_a];
    while (i > 0)
    {
        init->stack_a[i] = init->stack_a[i - 1];
        i--;
    }
    init->stack_a[0] = x;
    write(1 ,"ra\n", 3);
}

void    rb(t_stack *init)
{
    int i;
    int x;
    
    i = init->size_b;
    x = init->stack_b[init->size_b];
    while (i > 0)
    {
        init->stack_b[i] = init->stack_b[i - 1];
        i--;
    }
    init->stack_b[0] = x;
    write(1, "rb\n", 3);
}

void    rr(t_stack *init)
{
    ra(init);
    rb(init);
    write(1, "rr\n", 3);
}
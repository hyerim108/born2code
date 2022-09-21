/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nogada.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:46:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 11:50:24 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    argment_3(t_stack *init)
{
    if (init->stack_a[2] > init->stack_a[1])
        sa(init);
    if (init->stack_a[0] < init ->stack_a[1])
    {
        rra(init);
        if (init->stack_a[1] < init->stack_a[2])
            sa(init);
    }
}
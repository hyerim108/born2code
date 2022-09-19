/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:16:50 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/19 16:13:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack *init)
{
    write(1, "rra\n", 4);
}

void    rrb(t_stack *init)
{
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *init)
{
    rra(init);
    rrb(init);
    write(1, "rrr\n", 4);
}
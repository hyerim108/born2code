/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:05:43 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 11:39:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    send_sort(t_stack *init, int size, t_append *count)
{   
    if (check_a(init, size))
		return ;
    send_sort(init, count->pa - count->ra, count);
    send_a(init, count->rb);
    send_a(init, count->pb - count->rb);
}

void    send_a(t_stack *init, int size)
{
    t_append    count;
    int         i;
    
    if (check_b(init, size))
    {
        while (size--)
            pa(init);
        return ;
    }
    setting_pivot(init, size, 0);
    a_send_u(init, size, &count);
    send_sort(init, count.pa - count.ra, &count);
    send_sort(init, count.rb, &count);
    send_a(init, count.ra);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:25 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/12 19:39:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int    print_error()
{
    write(1, "Error\n", 6);
    return (-1);
}

t_stack stack_setting()
{
    t_stack *s;

    s = NULL;
    s->pre = NULL;
    s->content = 0;
    s->next = NULL;
    return (s);
}

t_content setting()
{
    t_stack     *stack;
    t_content   *content;
    
    stack = stack_setting();
    content->top_a = stack;
    content->bottom = stack;
    return (content);
}

int main(int ac, char **av)
{
    int     size;
    int     *number_array;
    t_stack *stack;
    
    stack = setting();
    if (ac == 1) return (0);
    size = factor_split(ac, av);
    number_array = number_check(ac, av, size);
    for(int i=0;i<ac-1;i++)
        printf("%d\n", number_array[i]);
    printf("%d", size);
}
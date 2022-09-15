/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:30:12 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/15 14:25:45 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int double_check(int *arr, int idx, int num)
{
    int i;

    i = 0;
    while (i < idx)
    {
        if(arr[i] == num)
            return (0);
        i++;
    }
    return (1);
}

void    checking(t_stack *init, int ac, char **av, int size)
{
    int     i;
    int     j;
    int     a; 
    char    **arr;
    
    i = 1;
    a = 0;
    while (i < ac)
    {
        arr = ft_split(av[i++], ' ');
        j = 0;
        while (arr[j])
        {
            if (!ft_atoi2(arr[j], &init->stack_a[a]) || 
                !double_check(init->a, a, &init->stack_a[a]))
                print_error();
            a++;
            j++; 
        }
    }
}

void    initialization_stack(t_stack *init, int size)
{
    init->stack_a = malloc(sizeof(t_stack) * size);
    init->stack_b = malloc(sizeof(t_stack) * size);
    init->size = 0;
}

void    setting(t_stack *init, int ac, char **av)
{
    int size;
    
    size = factor_split(ac, av);
    initialization_stack(init, size);
    checking(init, ac, av, size);
}

void    push_swap(int ac, char **av)
{
    t_stack init;
    
    setting(&init, ac, av);
}

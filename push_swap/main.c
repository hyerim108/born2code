/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:25 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/15 14:23:17 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int print_error()
{
    write(1, "Error\n", 6);
    return (-1);
}

int main(int ac, char **av)
{
    if (ac >= 2)
        push_swap(ac, av);
    return (0);
}
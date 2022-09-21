/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:25 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/21 19:07:45 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int num)
{
	if (num < 0)
		write(1, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		push_swap(ac, av);
	// while (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:51:55 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/06 18:13:51 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	main(int ac, char **av)
{
	t_param	p;

	if (ac != 2)
		error("argument Error");
	p.mlx = mlx_init();
	build_map(av[1], &p);
	return (0);
}

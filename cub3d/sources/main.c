/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:51:55 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/29 13:14:08 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	exit(1);
}

int	main(int ac, char **av)
{
	t_param	p;

	if (ac != 2)
		error("argument Error");
	build_map(av[1], &p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "CUB3D");
	go(&p);
	mlx_hook(p.win, 2, 0, &key_press, &p.move);
	mlx_hook(p.win, 3, 0, &key_release, &p.move);
	mlx_hook(p.win, 17, 0, &game_end, &p);
	mlx_loop_hook(p.mlx, &setting_loop, &p);
	mlx_loop(p.mlx);
	while(1);
	return (0);
}

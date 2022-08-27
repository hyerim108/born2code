/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:09:17 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/27 16:48:56 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <mlx.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_param	p;
	int		img_width;
	int		img_height;

	if (argc != 2)
		printf("ERROR\n");
	else
	{
		p.mlx = mlx_init();
		build_map(argv[1], &p);
		p.win = mlx_new_window(p.mlx, 500, 500, "so_long");
		mlx_hook(p.win, X_EVENT_KEY_RELEASE, 0, &key_press, &p);
		p.img = mlx_xpm_file_to_image(p.mlx, "./image/grass_tileset.xpm", &img_width, &img_height);
		mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
		mlx_loop(p.mlx);
	}
}

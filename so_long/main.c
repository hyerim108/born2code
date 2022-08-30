/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:09:17 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/28 20:24:54 by hyerimki         ###   ########.fr       */
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
		setting_img(&p);
		map_item_count(&p);
		p.win = mlx_new_window(p.mlx, p.width * 32, p.height * 32, "so_long");
		mlx_hook(p.win, X_EVENT_KEY_RELEASE, 0, &key_press, &p);
		paste_img(&p);
		mlx_loop(p.mlx);
	}
}

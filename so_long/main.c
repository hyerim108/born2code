/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:09:17 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/31 18:01:37 by hyerimki         ###   ########.fr       */
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
		error("argument error!");
	else
	{
		p.mlx = mlx_init();
		build_map(argv[1], &p);
		setting_img(&p);
		map_error_check(&p);
		p.win = mlx_new_window(p.mlx, p.width * 32, p.height * 32, "so_long");
		mlx_hook(p.win, X_EVENT_KEY_RELEASE, 0, &key_press, &p);
		mlx_hook(p.win, X_EVENT_KEY_EXIT, 0, &game_end, &p);
		paste_img(13, &p);
		mlx_loop(p.mlx);
	}
}

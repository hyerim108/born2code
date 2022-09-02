/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:09:17 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/02 16:31:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	congratulations(t_param *p)
{
	p->walk_cnt++;
	printf("%d\n", p->walk_cnt);
	printf("total walkcount : %d\n", p->walk_cnt);
	write(1, "congratulations!\n", 17);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_param	p;
	int		img_width;
	int		img_height;
	char	*point;

	if (argc != 2)
		error("argument error!");
	else
	{
		point = ft_strrchr(argv[1], '.');
		if (point == 0 || ft_strcmp(point, ".ber") != 0)
			error("file error!");
		p.mlx = mlx_init();
		build_map(argv[1], &p);
		setting_img(&p);
		map_error_check(&p);
		p.win = mlx_new_window(p.mlx, p.width * 32, p.height * 32, "so_long");
		mlx_hook(p.win, X_EVENT_KEY_RELEASE, 0, &key_press, &p);
		mlx_hook(p.win, X_EVENT_KEY_EXIT, 0, &game_end, &p);
		paste_img(1, &p);
		mlx_loop(p.mlx);
	}
}

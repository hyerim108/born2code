/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:06:21 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_texture_check(char *line, int i)
{
	if (ft_strncmp("i", line, 1) == 0)
	{
		if (ft_strncmp("img/EE.xpm", line, 10) != 0 && i == 3)
			error("img texture error");
		else if (ft_strncmp("img/NN.xpm", line, 10) != 0 && i == 2)
			error("img texture error");
		else if (ft_strncmp("img/SS.xpm", line, 10) != 0 && i == 1)
			error("img texture error");
		else if (ft_strncmp("img/WW.xpm", line, 10) != 0 && i == 4)
			error("img texture error");
	}
	else if (ft_strncmp("./", line, 2) == 0)
	{
		if (ft_strncmp("img/EE.xpm", line + 2, 10) != 0 && i == 3)
			error("img texture error");
		else if (ft_strncmp("img/NN.xpm", line + 2, 10) != 0 && i == 2)
			error("img texture error");
		else if (ft_strncmp("img/SS.xpm", line + 2, 10) != 0 && i == 1)
			error("img texture error");
		else if (ft_strncmp("img/WW.xpm", line + 2, 10) != 0 && i == 4)
			error("img texture error");
	}
	else
		error("Not img absolute path");
}

void	setting_image(t_param *p, t_image *img, t_map *map)
{
	int		i;
	char	*link;

	i = 0;
	link = NULL;
	while (++i < 5)
	{
		if (i == 1)
			link = map->so;
		else if (i == 2)
			link = map->no;
		else if (i == 3)
			link = map->ea;
		else
			link = map->we;
		map_texture_check(link, i);
		img->img_ptr = mlx_xpm_file_to_image(p->mlx, link, &img->x, &img->y);
		img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bits, \
				&img->size, &img->endian);
		fill_img(img, i);
		mlx_destroy_image(p->mlx, img->img_ptr);
	}
}

void	loading(t_image *img)
{
	int	i;

	i = -1;
	img->img_arr = (int **)malloc(5 * (sizeof(int *)));
	if (!img->img_arr)
		error("img_arr malloc Error");
	while (++i < 5)
	{
		img->img_arr[i] = (int *)malloc(sizeof(int) * BIT_H * BIT_W);
		if (!img->img_arr[i])
			error("img_err[i] malloc Error");
	}
}

void	go(t_param *p)
{
	loading(&p->img);
	setting_image(p, &p->img, &p->map);
	p->img.img_ptr = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->img.data = (int *)mlx_get_data_addr(p->img.img_ptr, &p->img.bits, \
			&p->img.size, &p->img.endian);
	player_init(&p->player);
}

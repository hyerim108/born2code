/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:54:06 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/30 15:06:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

void	float_img(t_param *p, int h, int w)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img.grass, w * 32, h * 32);
	if (p->str_line[p->width * h + w] == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->img.wall, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'C')
		mlx_put_image_to_window(p->mlx, p->win, p->img.cake, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'P')
		mlx_put_image_to_window(p->mlx, p->win, p->img.people, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'E')
		mlx_put_image_to_window(p->mlx, p->win, p->img.exit, w * 32, h * 32);
}

void	setting_img(t_param *p)
{
	int	iw;
	int	ih;

	p->img.grass = mlx_xpm_file_to_image(p->mlx, "./img/grass.xpm", &iw, &ih);
	p->img.wall = mlx_xpm_file_to_image(p->mlx, "./img/wall.xpm", &iw, &ih);
	p->img.cake = mlx_xpm_file_to_image(p->mlx, "./img/cake.xpm", &iw, &ih);
	p->img.people = mlx_xpm_file_to_image(p->mlx, "./img/rabbit.xpm", &iw, &ih);
	p->img.exit = mlx_xpm_file_to_image(p->mlx, "./img/exit.xpm", &iw, &ih);
}

void	paste_img(t_param *p)
{
	int	h;
	int	w;

	h = 0;
	while (h < p->height)
	{
		w = 0;
		while (w < p->width)
		{
			float_img(p, h, w);
			w++;
		}
		h++;
	}
}

void	build_map(char *build, t_param *p)
{
	int		fd;
	char	*line;

	fd = open(build, O_RDONLY);
	line = get_next_line(fd);
	p->width = ft_strlen(line) - 1;
	p->height = 0;
	p->str_line = ft_strdup_new(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		p->height++;
		if (line)
			p->str_line = ft_strjoin_new(p->str_line, line);
	}
	close(fd);
	printf("%s\n", p->str_line);
}

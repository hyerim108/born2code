/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:54:06 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/04 17:49:02 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	float_img(int key, t_param *p, int h, int w)
{
	mlx_put_image_to_window(p->mlx, p->win, p->img.grass, w * 32, h * 32);
	if (p->str_line[p->width * h + w] == '1')
		mlx_put_image_to_window(p->mlx, p->win, p->img.wall, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'C')
		mlx_put_image_to_window(p->mlx, p->win, p->img.cake, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'P' && key == KEY_D)
		mlx_put_image_to_window(p->mlx, p->win, p->img.r_d, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'P' && key == KEY_W)
		mlx_put_image_to_window(p->mlx, p->win, p->img.r_w, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'P' && key == KEY_A)
		mlx_put_image_to_window(p->mlx, p->win, p->img.r_a, w * 32, h * 32);
	else if (p->str_line[p->width * h + w] == 'P' && key == KEY_S)
		mlx_put_image_to_window(p->mlx, p->win, p->img.r_s, w * 32, h * 32);
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
	p->img.r_w = mlx_xpm_file_to_image(p->mlx, "./img/rabbit_w.xpm", &iw, &ih);
	p->img.r_a = mlx_xpm_file_to_image(p->mlx, "./img/rabbit_a.xpm", &iw, &ih);
	p->img.r_s = mlx_xpm_file_to_image(p->mlx, "./img/rabbit_s.xpm", &iw, &ih);
	p->img.r_d = mlx_xpm_file_to_image(p->mlx, "./img/rabbit_d.xpm", &iw, &ih);
	p->img.exit = mlx_xpm_file_to_image(p->mlx, "./img/exit.xpm", &iw, &ih);
}

void	paste_img(int keycode, t_param *p)
{
	int	h;
	int	w;

	h = 0;
	while (h < p->height)
	{
		w = 0;
		while (w < p->width)
		{
			float_img(keycode, p, h, w);
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
	if (fd <= 0)
		error("file error");
	line = get_next_line(fd);
	p->width = ft_strlen(line) - 1;
	p->height = 0;
	p->str_line = ft_strdup_new(line);
	free(line);
	build_map_error(fd, line, p);
	close(fd);
}

void	build_map_error(int fd, char *line, t_param *p)
{
	int	count;
	int	total;
	int final;
	
	while (line)
	{
		line = get_next_line(fd);
		p->height++;
		if (line)
		{
			count = ft_strlen(line) - 1;
			final = ft_strlen(line) - 1;
			total += count;
			p->str_line = ft_strjoin_new(p->str_line, line);
			if (count != p->width && total >= ft_strlen(p->str_line) - p->width)
				error("No rectangle");
		}
		free(line);
	}
}

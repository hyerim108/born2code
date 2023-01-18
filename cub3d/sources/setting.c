/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:46:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/18 17:14:13 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setting_buffer(t_ray *ray, t_image *img, int x)
{
	int	color;
	int	i;

	i = ray->drawStart;
	while (i < ray->drawEnd)
	{
		ray->texY = (int)ray->texPos & BIT_H - 1;
		if (ray->side == 0)
		{
			if (ray->ray_dirX >= 0)
				color = img->img_arr[1][64 * ray->texY + ray->texX];
			else
				color = img->img_arr[2][64 * ray->texY + ray->texX];
		}
		else if (ray->side == 1)
		{
			if (ray->ray_dirY >= 0)
				color = img->img_arr[3][64 * ray->texY + ray->texX];
			else
				color = img->img_arr[4][64 * ray->texY + ray->texX];
		}
		img->arr[i][x] = color;
		ray->texPos += ray->step;
		i++;
	}
}

void	build_map(char *av, t_param *p)
{
	if (ft_strcmp(".cub", &av[ft_strlen(&av[1]) - 3]) != 0)
		error("Not *.cub file");
	initialization_param(&p->map, av);
	initialization_image(&p->img);
	initialization_move(&p->move);
	map_parshing(av, p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:26:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:12:27 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_algolizm(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit != 1)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (map->map[ray->mapx][ray->mapy] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perpwalldist = ray->sidedistx - ray->deltadistx;
	else
		ray->perpwalldist = ray->sidedisty - ray->deltadisty;
}

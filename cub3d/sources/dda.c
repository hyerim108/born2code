/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:26:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 17:11:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_algolizm(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit != 1)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map->map[ray->mapX][ray->mapY] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->perpwallDist = ray->sideDistX - ray->deltaDistX;
	else
		ray->perpwallDist = ray->sideDistY - ray->deltaDistY;
}

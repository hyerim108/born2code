/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:00:05 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 17:31:56 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	DDA_algolism_prev(t_player *player, t_ray *ray)
{
	if (ray->ray_dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->pocus_x - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - player->pocus_x) * ray->deltaDistX;
	}
	if (ray->ray_dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->pocus_y - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - player->pocus_y) * ray->deltaDistY;
	}
}

void	initialization_ray(t_param *p, t_player *player, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIDTH - 1;
	ray->ray_dirX = player->dirX + player->planeX * camera;
	ray->ray_dirY = player->dirY + player->planeY * camera;
	ray->deltaDistX = fabs(1 / ray->ray_dirX);
	ray->deltaDistY = fabs(1 / ray->ray_dirY);
	ray->mapX = (int)player->pocus_x;
	ray->mapY = (int)player->pocus_y;
	DDA_algolism_prev(player, ray);
	return ;
}

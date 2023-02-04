/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:00:05 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:10:34 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_algolism_prev(t_player *player, t_ray *ray)
{
	if (ray->ray_dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->pocus_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->pocus_x) * ray->deltadistx;
	}
	if (ray->ray_diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->pocus_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->pocus_y) * ray->deltadisty;
	}
}

void	initialization_ray(t_param *p, t_player *player, t_ray *ray, int x)
{
	double	camera;

	camera = 2 * x / (double)WIDTH - 1;
	ray->ray_dirx = player->dirx + player->planex * camera;
	ray->ray_diry = player->diry + player->planey * camera;
	ray->deltadistx = fabs(1 / ray->ray_dirx);
	ray->deltadisty = fabs(1 / ray->ray_diry);
	ray->mapx = (int)player->pocus_x;
	ray->mapy = (int)player->pocus_y;
	dda_algolism_prev(player, ray);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_cover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:15:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 17:30:18 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line_height(t_ray *ray, t_player *p)
{
	ray->lineHeight = (int)(HEIGHT / ray->perpwallDist);
	ray->drawStart = HEIGHT / 2 - ray->lineHeight / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = HEIGHT / 2 + ray->lineHeight / 2;
	if (ray->drawEnd >= HEIGHT)
		ray->drawEnd = HEIGHT;
	ray->step = 1.0 * 64 / ray->lineHeight;
	ray->texPos = (ray->drawStart - HEIGHT / \
			2 + ray->lineHeight / 2) * ray->step;
}

void	perp_cover(t_ray *ray, t_player *p)
{
	double	wall;

	if (ray->side == 0)
		wall = p->pocus_y + (ray->perpwallDist * ray->ray_dirY);
	else
		wall = p->pocus_x + (ray->perpwallDist * ray->ray_dirX);
	wall = wall - floor(wall);
	ray->texX = (int)(wall * (double)64);
	if (ray->side == 0 && ray->ray_dirX > 0)
		ray->texX = 64 - ray->texX -1;
	if (ray->side == 1 && ray->ray_dirY < 0)
		ray->texX = 64 - ray->texX -1;
}

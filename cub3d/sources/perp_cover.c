/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perp_cover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:15:04 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:08:15 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line_height(t_ray *ray, t_player *p)
{
	ray->lineheight = (int)(HEIGHT / ray->perpwalldist);
	ray->drawstart = HEIGHT / 2 - ray->lineheight / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = HEIGHT / 2 + ray->lineheight / 2;
	if (ray->drawend >= HEIGHT)
		ray->drawend = HEIGHT;
	ray->step = 1.0 * 64 / ray->lineheight;
	ray->texpos = (ray->drawstart - HEIGHT / \
			2 + ray->lineheight / 2) * ray->step;
}

void	perp_cover(t_ray *ray, t_player *p)
{
	double	wall;

	if (ray->side == 0)
		wall = p->pocus_y + (ray->perpwalldist * ray->ray_diry);
	else
		wall = p->pocus_x + (ray->perpwalldist * ray->ray_dirx);
	wall = wall - floor(wall);
	ray->texx = (int)(wall * (double)64);
	if (ray->side == 0 && ray->ray_dirx > 0)
		ray->texx = 64 - ray->texx -1;
	if (ray->side == 1 && ray->ray_diry < 0)
		ray->texx = 64 - ray->texx -1;
}

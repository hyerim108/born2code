/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:26:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/16 17:41:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    dda_algolizm(t_ray *ray, t_map *map, t_player *p)
{
    int hit;
    
    hit = 0;
    while (hit == 0)
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
        ray->perpwallDist = (ray->mapX - p->pocus_x + (1 - ray->stepX) / 2);
    else
        ray->perpwallDist = (ray->mapY - p->pocus_y + (1 - ray->stepY) / 2);
}
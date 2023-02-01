/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:08 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 17:14:30 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	push_direct_left(t_player *p)
{
	double	oldDir;
	double	oldPlane;
	double	site;

	site = p->sprite;
	oldDir = p->dirX;
	oldPlane = p->planeX;
	p->dirX = p->dirX * cos(site) - p->dirY * sin(site);
	p->dirY = oldDir * sin(site) + p->dirY * cos(site);
	p->planeX = p->planeX * cos(site) - p->planeY * sin(site);
	p->planeY = oldPlane * sin(site) + p->planeY * cos(site);
}

void	push_direct_right(t_player *p)
{
	double  oldDir;
	double  oldPlane;
	double		site;

	site = -(p->sprite);
	oldDir = p->dirX;
	oldPlane = p->planeX;
	p->dirX = p->dirX * cos(site) - p->dirY * sin(site);
	p->dirY = oldDir * sin(site) + p->dirY * cos(site);
	p->planeX = p->planeX * cos(site) - p->planeY * sin(site);
	p->planeY = oldPlane * sin(site) + p->planeY * cos(site);
}

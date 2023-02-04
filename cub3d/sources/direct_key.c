/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:40:08 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:13:32 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	push_direct_left(t_player *p)
{
	double	olddir;
	double	oldplane;
	double	site;

	site = p->sprite;
	olddir = p->dirx;
	oldplane = p->planex;
	p->dirx = p->dirx * cos(site) - p->diry * sin(site);
	p->diry = olddir * sin(site) + p->diry * cos(site);
	p->planex = p->planex * cos(site) - p->planey * sin(site);
	p->planey = oldplane * sin(site) + p->planey * cos(site);
}

void	push_direct_right(t_player *p)
{
	double	olddir;
	double	oldplane;
	double	site;

	site = -(p->sprite);
	olddir = p->dirx;
	oldplane = p->planex;
	p->dirx = p->dirx * cos(site) - p->diry * sin(site);
	p->diry = olddir * sin(site) + p->diry * cos(site);
	p->planex = p->planex * cos(site) - p->planey * sin(site);
	p->planey = oldplane * sin(site) + p->planey * cos(site);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:13:53 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/27 17:23:55 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	push_key_w(t_player *p, t_map *map)
{
	double	x;
	double	y;
	
	x = p->dirX * p->moveScreen;
	y = p->dirY * p->moveScreen;
	if (map->map[(int)(p->pocus_x + y)][(int)(p->pocus_y)] == '0')
		p->pocus_x += y;
	if (map->map[(int)(p->pocus_x)][(int)(p->pocus_y + x)] == '0')
		p->pocus_y += x;
}

int key(t_move *move, t_player *play, t_map *map)
{
	if (move->w && !move->s)
		push_key_w(play, map);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:13:53 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 16:25:52 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	push_key_d(t_player *p, t_map *map)
{
	double	x;
	double	y;
	
	x = p->dirX * p->moveScreen;
	y = p->dirY * p->moveScreen;
	if (map->map[(int)(p->pocus_x + y * 2)][(int)(p->pocus_y)] == '0')
		p->pocus_x += y;
	if (map->map[(int)(p->pocus_x)][(int)(p->pocus_y - x * 2)] == '0')
		p->pocus_y -= x;
}
void	push_key_a(t_player *p, t_map *map)
{
	double	x;
	double	y;
	
	x = p->dirX * p->moveScreen;
	y = p->dirY * p->moveScreen;
	if (map->map[(int)(p->pocus_x - y * 2)][(int)(p->pocus_y)] == '0')
		p->pocus_x -= y;
	if (map->map[(int)(p->pocus_x)][(int)(p->pocus_y + x * 2)] == '0')
		p->pocus_y += x;
}

void	push_key_s(t_player *p, t_map *map)
{
	double	x;
	double	y;
	
	x = p->dirX * p->moveScreen;
	y = p->dirY * p->moveScreen;
	if (map->map[(int)(p->pocus_x - x * 1.1)][(int)(p->pocus_y)] == '0')
		p->pocus_x -= x;
	if (map->map[(int)(p->pocus_x)][(int)(p->pocus_y - y * 1.1)] == '0')
		p->pocus_y -= y;
}

void	push_key_w(t_player *p, t_map *map)
{
	double	x;
	double	y;
	
	x = p->dirX * p->moveScreen;
	y = p->dirY * p->moveScreen;
	if (map->map[(int)(p->pocus_x + x * 1.1)][(int)(p->pocus_y)] == '0')
		p->pocus_x += x;
	if (map->map[(int)(p->pocus_x)][(int)(p->pocus_y + y * 1.1)] == '0')
		p->pocus_y += y;
}

int key(t_move *move, t_player *play, t_map *map)
{
	if (move->d && !move->a)
		push_key_d(play, map);
	if (move->a && !move->d)
		push_key_a(play, map);
	if (move->s && !move->w)
		push_key_s(play, map);
	if (move->w && !move->s)
		push_key_w(play, map);
	if (move->left && !move->right)
		push_direct_left(play);
	if (move->right && !move->left)
		push_direct_right(play);
	return (1);
}
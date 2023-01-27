/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:37:47 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/27 17:08:16 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_param(t_map *map, char *av)
{
	map->map = NULL;
	map->EA = NULL;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->height = 0;
	map->width = 0;
	map->celling = 0;
	map->floor = 0;
    map->map_first = 0;
    map->map_line = 0;
}

void	initialization_image(t_image *img)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	img->size = 0;
	img->bits = 0;
	img->endian = 0;
	img->data = NULL;
	img->img_ptr = NULL;
	img->img_arr = NULL;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			img->arr[i][j++] = 0;
		i++;
	}
}

void	initialization_move(t_move *move)
{
	move->w = 0;
	move->a = 0;
	move->s = 0;
	move->d = 0;
}

void	player_init(t_player *p)
{
	p->dirX = 0;
	p->dirY = 0;
	if(p->status == 'S')
	{
		p->dirX = 1;
		p->planeY = -0.66;
	}
	else if(p->status == 'N')
	{
		p->dirX = -1;
		p->planeY = 0.66;
	}
	else if (p->status == 'W')
	{
		p->dirY = -1;
		p->planeX = -0.66;
	}
	else if (p->status == 'E')
	{
		p->dirY = 1;
		p->planeX = 0.66;
	}
	p->moveScreen = 0.05;
	p->sprite = 0.05;
}
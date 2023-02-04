/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:37:47 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:04:12 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialization_param(t_map *map, char *av)
{
	map->map = NULL;
	map->ea = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
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
	move->left = 0;
	move->right = 0;
}

void	player_init(t_player *p)
{
	p->dirx = 0;
	p->diry = 0;
	if (p->status == 'S')
	{
		p->dirx = 1;
		p->planey = -0.66;
	}
	else if (p->status == 'N')
	{
		p->dirx = -1;
		p->planey = 0.66;
	}
	else if (p->status == 'W')
	{
		p->diry = -1;
		p->planex = -0.66;
	}
	else if (p->status == 'E')
	{
		p->diry = 1;
		p->planex = 0.66;
	}
	p->movescreen = 0.05;
	p->sprite = 0.05;
}

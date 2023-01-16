/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:21 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/16 17:54:58 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void    paint_img(t_param *p, t_image *img)
{
    int x;
    int y;

    x = -1;
    while (++x < HEIGHT)
    {
        y = -1;
        while (++y < WIDTH)
            img->data[x * WIDTH + y] = img->arr[x][y];
    }
    mlx_put_image_to_window(p->mlx, p->win, img->img_ptr, 0, 0);
}

void    pating_floor_celling(t_param *p, t_map *map)
{
    int i;
    int j;
    int celling;
    int floor;

    i = 0;
    floor = map->floor;
    celling = map->celling;
    while (i < HEIGHT / 2)
    {
        j = 0;
        while (j < WIDTH)
        {
            p->img.arr[i][j] = celling;
            p->img.arr[HEIGHT - i - 1][j] = floor;
            j++;
        }
        i++;
    }
}
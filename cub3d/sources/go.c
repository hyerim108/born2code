/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:00 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/27 12:58:06 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    fill_img(t_image *img, int num)
{
    int x;
    int y;
    
    y = 0;
    while (y < img->y)
    {
        x = 0;
        while (x < img->x)
        {
            img->img_arr[num][img->x * y + x] = img->data[img->y * y + x];
            x++; 
        }
        y++;
    }  
}

void    setting_image(t_param *p, t_image *img, t_map *map)
{
    int     i;
    char    *link;
    
    i = 0;
    link = NULL;
    while (++i < 5)
    {
        if (i == 1)
            link = map->SO;
        else if (i == 2)
            link = map->NO;
        else if (i == 3)
            link = map->WE;
        else
            link = map->EA;
        img->img_ptr = mlx_xpm_file_to_image(p->mlx, link, &img->x, &img->y);
        img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bits, \
                    &img->size, &img->endian);
        fill_img(img, i);
        mlx_destroy_image(p->mlx, img->img_ptr);
    }
}

void    loading(t_image *img)
{
    int i;
    
    i = -1;
    img->img_arr = (int **)malloc(5 * (sizeof(int *)));
    if (!img->img_arr)
        error("img_arr malloc Error");
    while (++i < 5)
    {
        img->img_arr[i] = (int *)malloc(sizeof(int) * BIT_H * BIT_W);
        if (!img->img_arr[i])
            error("img_err[i] malloc Error");
    }
}

void    go(t_param *p)
{
    loading(&p->img);
    setting_image(p, &p->img, &p->map);
    p->img.img_ptr = mlx_new_image(p->mlx, WIDTH, HEIGHT);
    p->img.data = (int *)mlx_get_data_addr(p->img.img_ptr, &p->img.bits, \
        &p->img.size, &p->img.endian);
    player_init(&p->player);
}
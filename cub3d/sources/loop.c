/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:23:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/18 15:01:29 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int setting_loop(t_param *p)
{
    pating_floor_celling(p, &p->map);
    raycasting(p);
    paint_img(p, &p->img);
    return (0);
}
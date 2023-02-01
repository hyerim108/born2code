/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:23:58 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 17:22:03 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	setting_loop(t_param *p)
{
	pating_floor_celling(p, &p->map);
	raycasting(p);
	paint_img(p, &p->img);
	key(&p->move, &p->player, &p->map);
	return (0);
}

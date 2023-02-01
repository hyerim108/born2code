/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:57:17 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 16:43:31 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_param *p)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		initialization_ray(p, &p->player, &p->ray, x);
		dda_algolizm(&p->ray, &p->map);
		perp_cover(&p->ray, &p->player);
		line_height(&p->ray, &p->player);
		setting_buffer(&p->ray, &p->img, x);
	}
}

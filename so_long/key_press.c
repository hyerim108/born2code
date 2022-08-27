/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:02:52 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/26 16:02:01 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_A)
		param->y--;
	else if (keycode == KEY_D)
		param->y++;
	else if (keycode == KEY_W)
		param->x++;
	else if (keycode == KEY_S)
		param->x--;
	else if (keycode == KEY_ESC)
		exit(0);
	// printf("%d %d\n", param->x, param->y);
	return (0);
}
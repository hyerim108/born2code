/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:24:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/16 12:42:27 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_param *param)
{
    // if (keycode == KEY_A)
	// 	pushkey_a(keycode, param);
	// else if (keycode == KEY_D)
	// 	pushkey_d(keycode, param);
	// else if (keycode == KEY_W)
	// 	pushkey_w(keycode, param);
	// else if (keycode == KEY_S)
	// 	pushkey_s(keycode, param);
	// else 
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
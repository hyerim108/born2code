/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:24:09 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/01 13:54:26 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_move *move)
{
    if (keycode == KEY_A)
		move->a = 1;
	else if (keycode == KEY_D)
		move->d = 1;
	else if (keycode == KEY_W)
		move->w = 1;
	else if (keycode == KEY_S)
		move->s = 1;
	else if (keycode == K_LEFT)
		move->left++;
	else if (keycode == K_RIGHT)
		move->right++;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int key_release(int keycode, t_move *move)
{
	if (keycode == KEY_A)
		move->a = 0;
	else if (keycode == KEY_D)
		move->d = 0;
	else if (keycode == KEY_W)
		move->w = 0;
	else if (keycode == KEY_S)
		move->s = 0;
	else if (keycode == K_LEFT)
		move->left = 0;
	else if (keycode == K_RIGHT)
		move->right = 0;
	return (0);
}

int	game_end(t_param *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}
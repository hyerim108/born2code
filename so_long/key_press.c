/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:02:52 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/30 14:23:22 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_A)
		pushkey_a(param);
	else if (keycode == KEY_D)
		pushkey_d(param);
	else if (keycode == KEY_W)
		pushkey_w(param);
	else if (keycode == KEY_S)
		pushkey_s(param);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

void	pushkey_w(t_param *p)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'P')
			break ;
	}
	if (p->str_line[i - p->width] != '1')
	{
		p->str_line[i] = '0';
		p->str_line[i - p->width] = 'P';
		p->walk_cnt++;
		printf("%d\n", p->walk_cnt);
		paste_img(p);
	}
}

void	pushkey_s(t_param *p)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'P')
			break ;
	}
	if (p->str_line[i + p->width] != '1')
	{
		p->str_line[i] = '0';
		p->str_line[i + p->width] = 'P';
		p->walk_cnt++;
		printf("%d\n", p->walk_cnt);
		paste_img(p);
	}
}

void	pushkey_a(t_param *p)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'P')
			break ;
	}
	if (p->str_line[i - 1] != '1')
	{
		p->str_line[i] = '0';
		p->str_line[i - 1] = 'P';
		p->walk_cnt++;
		printf("%d\n", p->walk_cnt);
		paste_img(p);
	}
}

void	pushkey_d(t_param *p)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(p->str_line))
	{
		if (p->str_line[i] == 'P')
			break ;
	}
	if (p->str_line[i + 1] != '1')
	{
		p->str_line[i] = '0';
		p->str_line[i + 1] = 'P';
		p->walk_cnt++;
		printf("%d\n", p->walk_cnt);
		paste_img(p);
	}
}

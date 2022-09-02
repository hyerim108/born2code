/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:25:11 by hyerimki          #+#    #+#             */
/*   Updated: 2022/09/02 17:51:47 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h> //exit
# include <stdio.h>
# include "gnl/get_next_line.h"

typedef struct s_content
{
	void	*grass;
	void	*wall;
	void	*cake;
	void	*r_w;
	void	*r_a;
	void	*r_s;
	void	*r_d;
	void	*exit;
}	t_con;
typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_con	img;
	int		x;
	int		y;
	int		width;
	int		height;
	int		all_tem;
	int		item_count;
	int		walk_cnt;
	char	*str_line;
}	t_param;

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
// # define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT		17 //exit key code

char	*ft_strjoin_new(char *s1, char *s2);
char	*ft_strdup_new(const char *s1);
int		key_press(int keycode, t_param *param);
void	build_map(char *build, t_param *p);
void	paste_img(int keycode, t_param *p);
void	setting_img(t_param *p);
void	pushkey_w(int keycode, t_param *p);
void	pushkey_s(int keycode, t_param *p);
void	pushkey_a(int keycode, t_param *p);
void	pushkey_d(int keycode, t_param *p);
void	error(char *str);
int		game_end(t_param *p);
void	map_error_check(t_param *p);
void	map_item_count(t_param *p);
void	map_wall_check(t_param *p);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	map_error_print(int e, int people, int another, t_param *p);
void	congratulations(t_param *p);

#endif

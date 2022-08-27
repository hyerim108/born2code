/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:25:11 by hyerimki          #+#    #+#             */
/*   Updated: 2022/08/27 16:47:17 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h> //exit
# include "gnl/get_next_line.h"

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		width;
	int		height;
	char	*str_line;
}	t_param;

typedef struct s_content
{
	int	img;
	int	img2;
}	t_content;

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
// # define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
// # define X_EVENT_KEY_EXIT		17 //exit key code

int		key_press(int keycode, t_param *param);
void	build_map(char *build, t_param *p);

#endif
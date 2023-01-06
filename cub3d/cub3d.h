/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:41:45 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/06 18:12:49 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "gnl/get_next_line.h"

# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT   17

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53

# define KEY_Q 12
# define KEY_E 14
# define KEY_R 15

typedef struct s_image
{
	void	*img_ptr;
	int		*data;

	int		size;
	int		endian;
	int		bits;
}	t_image;

typedef struct s_param
{
	void	*mlx;
	void	*win;
}	t_param;

/* main */
void	error(char *str);

/* setting */
void	build_map(char *av, t_param *p);

/* utils */
int		ft_strcmp(const char *s1, const char *s2);

#endif

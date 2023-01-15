/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:41:45 by hyerimki          #+#    #+#             */
/*   Updated: 2023/01/15 13:38:50 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "lib/lib.h"

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

# define WIDTH 970
# define HEIGHT 720
# define BIT_W 64
# define BIT_H 64

typedef	struct s_color
{
	/* data */
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_player
{
	char	status;
	double	pocus_x;
	double	pocus_y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	moveScreen;
	double	sprite;
}	t_player;

typedef struct s_move
{
	int	w;
	int	s;
	int	a;
	int	d;
}	t_move;

typedef struct s_map
{
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;

	int		floor;
	int		celling;
	int		width;
	int		height;
	int		map_line;
	int		map_first;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	int		*data;
	
	int		size;
	int		endian;
	int		bits;

	int		arr[HEIGHT][WIDTH];
	int		**img_arr;

	int		x;
	int		y;
}	t_image;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	
	t_map		map;
	t_player	player;
	t_image		img;
	t_move		move;
}	t_param;

/* main */
void	error(char *str);

/* setting */
void	build_map(char *av, t_param *p);

/* color.c */
void    parsing_color_check(t_map *map, char *line, char c);

/* parsing */
int 	map_parshing(char *av, t_param *p);

/* init */
void 	initialization_param(t_map *map, char *av);
void	initialization_image(t_image *img);
void	initialization_move(t_move *move);
void	player_init(t_player *player);

/* map */
void    map_save(t_map *map, t_player *p, char *line);
void	set_map(char *av, t_map *map);

/* check */
void    map_condition(t_map *map, char **str);
void	player_location_setting(t_player *play, char **str, int size);

/* key_action */
int		game_end(t_param *p);

/* key_press*/
int		key_press(int keycode, t_param *param);

/* loop */
int		setting_loop(t_param *p);

/* paint */
void    pating_floor_celling(t_param *p, t_map *map);

/* go */
void    go(t_param *p);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:41:45 by hyerimki          #+#    #+#             */
/*   Updated: 2023/02/02 13:24:27 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "lib/lib.h"

# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT   17

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53

# define K_LEFT 123
# define K_RIGHT 124

# define WIDTH 1500
# define HEIGHT 1000
# define BIT_W 64
# define BIT_H 64

# define X 0
# define Y 1

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	double	ray_dirx;
	double	ray_diry;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	double	perpwalldist;
	double	texpos;
	double	step;
	int		stepx;
	int		stepy;
	int		side;
	int		texx;
	int		texy;
	int		drawend;
	int		drawstart;
	int		lineheight;
}	t_ray;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_player
{
	char	status;
	double	pocus_x;
	double	pocus_y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movescreen;
	double	sprite;
}	t_player;

typedef struct s_move
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_move;

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;

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
	void		*mlx;
	void		*win;

	t_map		map;
	t_player	player;
	t_image		img;
	t_move		move;
	t_ray		ray;
}	t_param;

/* main */
void	error(char *str);

/* setting */
void	build_map(char *av, t_param *p);
void	setting_buffer(t_ray *ray, t_image *img, int x);

/* color.c */
void	parsing_color_check(t_map *map, char *line, char c);

/* parsing */
int		map_parshing(char *av, t_param *p);

/* init */
void	initialization_param(t_map *map, char *av);
void	initialization_image(t_image *img);
void	initialization_move(t_move *move);
void	player_init(t_player *player);

/* map */
void	map_save(t_map *map, t_player *p, char *line);
void	set_map(char *av, t_map *map);

/* check */
void	map_condition(t_map *map, char **str);
void	player_location_setting(t_player *play, char **str, int size);

/* key_action */
int		key(t_move *move, t_player *play, t_map *map);

/* key_press*/
int		key_press(int keycode, t_move *move);
int		key_release(int keycode, t_move *move);
int		game_end(t_param *p);

/* loop */
int		setting_loop(t_param *p);

/* paint */
void	pating_floor_celling(t_param *p, t_map *map);
void	paint_img(t_param *p, t_image *img);
void	fill_img(t_image *img, int num);

/* go */
void	go(t_param *p);

/* raycasting */
void	raycasting(t_param *p);

/* init_ray */
void	initialization_ray(t_param *p, t_player *player, t_ray *ray, int x);

/* dda */
void	dda_algolizm(t_ray *ray, t_map *map);

/* perp_cover.c */
void	perp_cover(t_ray *ray, t_player *p);
void	line_height(t_ray *ray, t_player *p);

/* direct_key.c*/
void	push_direct_right(t_player *p);
void	push_direct_left(t_player *p);

#endif

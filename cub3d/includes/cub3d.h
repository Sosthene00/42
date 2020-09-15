/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:55:19 by agaubert          #+#    #+#             */
/*   Updated: 2020/09/04 19:55:21 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <X11/Xlib.h>
# include "mlx_int.h"

# define EXPECTED_ARG 8
# define WALLS "NOSOEAWE"
# define PLAYER_START "NSEW"
# define SEP '+'

# define SCREEN_MIN_W 200
# define SCREEN_MIN_H 200

# define KEY_ESC		0xff1b
# define KEY_UP			0x77
# define KEY_DOWN		0x73
# define KEY_LEFT		0xff51
# define KEY_RIGHT		0xff53
# define STRAFE_RIGHT	0x64
# define STRAFE_LEFT	0x61

# define KEY_PRESS_MASK 	1L
# define KEY_RELEASE_MASK  	2L
# define KEY_PRESS 2
# define KEY_RELEASE 3

<<<<<<< HEAD
# define DESTROY_NOTIFY	33
=======
# define DESTROY_NOTIFY	17
>>>>>>> WIP memory
# define STRUCTURE_NOTIFY_MASK 1L<<17

# define WRONG_FILE "Error\nFile absent or wrong extension\n"
# define ERROR_PARSING "Error\nIncorrect map file content\n"
# define ERROR_WRITING	"Error\nCouldn't save a screenshot\n"
# define MEMORY_ERROR "Error\nmemory error while initializing mlx or malloc\n"
# define WRONG_ARG "Warning\nsecond argument can only be \"--save\"\n"
# define SCREEN_EXIST "Warning\nscreen already exists, ignoring new values\n"
# define COLOR_EXIST "Warning\ncolor already exists, ignoring new values\n"

# define FILE_EXT "cub"
# define SCREENSHOT_OPT "--save"

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	t_dxy			pos;
	t_dxy			dir;
	t_dxy			plane;
	double			speed_turn;
	double			speed_move;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
	char			strafe_right;
	char			strafe_left;
}					t_ply;

typedef struct		s_ray
{
	t_dxy			pos;
	t_dxy			dir;
	t_ixy			map;
	t_dxy			side;
	t_dxy			delta;
	t_ixy			step;
	double			dist;
	double			cam;
	double			wall_x;
	int				wall_height;
	int				wall_top;
	int				wall_bottom;
	int				hit;
	int				hit_side;
	int				tex_x;
	int				tex_y;
	double			*zbuffer;
}					t_ray;

typedef struct		s_clr
{
	unsigned int	sky;
	unsigned int	floor;
}					t_clr;

typedef	struct		s_image
{
	void			*img_ptr;
	char			*data;
	int				width;
	int				height;
	int				bits_per_pixel;
	int				size_line;
	int				endianness;
	int				order;
	int				amt;
	double			map_x;
	double			map_y;
	double			distance;
	struct s_image	*next;
}					t_ima;

typedef	struct		s_bmp
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixel_data_offset;
	unsigned int	headersize;
	int				image_width;
	int				image_height;
	unsigned short	planes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	imagesize;
	int				x_pixels_per_meter;
	int				y_pixels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}					t_bmp;

typedef	struct		s_ctx
{
	t_ply			player;
	t_clr			color;
	t_ray			ray;
	t_ima			screen;
	t_ima			n_wall;
	t_ima			e_wall;
	t_ima			w_wall;
	t_ima			s_wall;
	t_ima			sprite;
	t_bmp			screenshot;
	void			*mlx_ptr;
	void			*win_ptr;
	int				fd;
	int				do_screenshot;
	int				complete;
	int				map_width;
	int				map_height;
	char			**map;
}					t_ctx;

typedef struct		s_sprt
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				vmove_screen;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
}					t_sprt;

t_ctx				*init_ctx(char *filename);

void				init_win(t_ctx *c);
void				init_img(t_ctx *c);

int					loop_hook(t_ctx *c);

int					key_press(int key, t_ctx *c);

int					key_release(int key, t_ctx *c);

int					key_hook(int key, t_ctx *c);

int					check_file_extension(char *filename);

int					parse_file(char *map_file, t_ctx *c);

int					extract_textures(char **items, t_ctx *c);

int					read_map(t_ctx *c);

void				print_error(int error_code);

void				move_up(t_ctx *c);

void				move_down(t_ctx *c);

void				move_right(t_ctx *c);

void				move_left(t_ctx *c);

void				put_pxl(t_ima *screen, int x, int y, unsigned int color);

void				exit_program(t_ctx *c, int error_code);

void				raycasting(t_ctx *c);

void				draw_line(t_ctx *c, t_ima *texture, int x);

unsigned int		extract_color(t_ctx *c, t_ima *texture);

void				adapt_screen_size(t_ctx *c);

void				calc_tex_x(t_ctx *c, t_ima *tex);

t_ima				*wall_orientation(t_ctx *c);

int					update_sprite(t_ctx *c, int x, int y);

void				draw_sprite(t_ctx *c, t_ima *sprite);

void				order_sprite_dist(t_ctx *c, t_ima *sprite);

t_sprt				*init_sprite(t_ctx *c, t_ima *sprite);

void				get_values(t_ctx *c, t_sprt *sprite);

void				draw_stripes(t_ctx *c, t_ima *texture, t_sprt *sprite);

void				free_all(t_ctx *c);

void				save_screenshot(t_ctx *c);

int					exit_hook(t_ctx *c);

int					is_complete(t_ctx *c);

unsigned int		convert_color(int r, int g, int b);

int					get_xy_value(char **val, t_ctx *c);

int					get_color(char **items, t_ctx *c);

int					update_data(char **items, t_ctx *c);

void				follow_wall(char **map, t_ixy start, int x, int y);

void				strafe_right(t_ctx *c);

void				strafe_left(t_ctx *c);

int					is_map(char *line);

#endif

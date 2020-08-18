/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:42:49 by agaubert          #+#    #+#             */
/*   Updated: 2020/02/27 18:36:30 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./libft/libft.h"
# include "./mlx.h"
# include <math.h>
# include <time.h> // don't forget to delete later

# define EXPECTED_ARG 8
# define RESOLUTION 'R'
# define CEILING 'C'
# define FLOOR 'F'
# define SPRITE 'S'
# define WALLS "NOSOEAWE"
# define PLAYER_START "NSEW"
# define MAP_CASE "012"
# define SEP '+'

// All the mapping has been done on my AZERTY Ubuntu laptop, it might not work as expected
//# define KEY_UP 0x0077 //'w' on AZERTY keyboard
# define KEY_UP 0x007a //'z' on AZERTY keyboard
//# define KEY_LEFT 0x0061 //'a' on AZERTY
# define KEY_LEFT 0x0071 //'q' on AZERTY
# define KEY_RIGHT 0x0064 // 'd' on AZERTY
# define KEY_DOWN 0x0073
# define KEY_ESC 0xff1b

# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE_MASK  (1L<<1)  
# define KEY_PRESS 2
# define KEY_RELEASE 3

# define WRONG_FILE "Error\nSomething's wrong with the map file:\n"\
                    "Check that the file exists and its content is formatted correctly\n"
# define ERROR_PARSING "Error\nIncorrect map file content\n"
# define ERROR_WRITING	"Error\nSomething went wrong while saving a screenshot\n"
# define MEMORY_ERROR "Error\nmemory error while initializing mlx or malloc\n"

# define FILE_EXT "cub"
# define SCREENSHOT_OPT "--save"

#define uDiv 1
#define vDiv 1
#define vMove 0.0

typedef struct		int_xy
{
	int				x;
	int				y;
}					ixy;

typedef struct		double_xy
{
	double			x;
	double			y;
}					dxy;

typedef struct		player
{
	dxy	            pos;
	dxy	            dir;
	dxy	            plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
}					ply;

typedef struct		s_ray
{
	dxy				pos;
	dxy				dir;
	ixy				map;
	dxy				side;
	dxy				delta;
	ixy				step;
	double			dist;
	double			cam;
	double			wall_x;
	int				hit;
	int				hit_side;
	int				tex_x;
	int				tex_y;
	double			*zbuffer;
}					ray;

typedef struct      color
{
    unsigned int    sky;
    unsigned int    floor;
}                   clr;

typedef	struct 		image
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
	struct	image	*next;
}					img;


typedef	struct		context
{
    ply             player;
    clr             color;
	ray				ray;
    img	        	screen;
    img	        	N_wall;
    img	        	E_wall;
    img	        	W_wall;
    img	        	S_wall;
    img	        	sprite;
    void            *mlx_ptr;
    void            *win_ptr;
	int				fd;
	int				screenshot;
	int				complete;
	int				map_width;
	int				map_height;
	char			**map;
}					ctx;

typedef struct		sprite
{
	double			spriteX;
	double			spriteY;
	double			invDet;
	double			transformX;
	double			transformY;
	int				screenX;
	int				vMoveScreen;
	int				height;
	int				width;
	int				drawStartX;
	int				drawStartY;
	int				drawEndX;
	int				drawEndY;
}					sprt;

ctx                 *init_ctx(char *filename);

int	                init_win(ctx *c);

int                 loop_hook(ctx *c);

int		            key_press(int key, ctx *c);

int                 key_release(int key, ctx *c);

int	                key_hook(int key, ctx *c);

int                 check_file_extension(char *filename);

int                 parse_file(char *map_file, ctx *c);

int 				extract_textures(char **items, ctx *c);

int					read_map(ctx *c);

void                print_error(int error_code);

void                move_up(ctx *c);

void                move_down(ctx *c);

void				move_right(ctx *c);

void				move_left(ctx *c);

void			    put_pxl(img *img, int x, int y, unsigned int color);

void                exit_program(ctx *c, int error_code);

void				raycasting(ctx *c);

void				draw_line(ctx *c, img *texture, int x, int wall_top, int wall_bottom);

unsigned int 		extract_color(ctx *c, img *texture);

void 				adapt_screen_size(ctx *c);

void				calc_tex_x(ctx *c, img *tex);

img 				*wall_orientation(ctx *c);

int					update_sprite(ctx *c, int x, int y);

void				draw_sprite(ctx *c, img *sprite);

void				order_sprite_dist(ctx *c, img *sprite);

sprt    			*init_sprite(ctx *c, img *sprite);

void 				get_values(ctx *c, sprt *sprite);

void   				draw_stripes(ctx *c, img *texture, sprt *sprite);

void			    free_all(ctx *c);

#endif

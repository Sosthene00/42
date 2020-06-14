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

# define RESOLUTION "R "
# define CEILING "C "
# define FLOOR "F "
# define PLAYER_START "NSEW"
# define MAP_CASE "012"

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

# define WRONG_FILE "Something's wrong with the map file:\n"\
                    "Check that the file exists and its content is formatted correctly\n"
# define ERROR_PARSING "Error parsing map file content\n"
# define MEMORY_ERROR "Error while initializing mlx or malloc\n"

# define FILE_EXT "cub"

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
	int				hit;
	int				hit_side;
}					ray;

typedef struct      color
{
    unsigned int    N;
    unsigned int    S;
    unsigned int    E;
    unsigned int    W;
    unsigned int    sky;
    unsigned int    floor;
}                   clr;

typedef	struct		c
{
    ply             player;
    clr             color;
	ray				ray;
    void            *mlx_ptr;
    void            *win_ptr;
    int             win_x;
    int             win_y;
	void			*img;
	char			*pxl;
	int				bits_per_pixel;
	int				size_line;
	int				ed;
	int				complete;
	int				map_width;
	int				map_height;
	char			**map;
}					ctx;

ctx                 *init_ctx(char *filename);

void                init_win(ctx *c);

int                 loop_hook(ctx *c);

int		            key_press(int key, ctx *c);

int                 key_release(int key, ctx *c);

int	                key_hook(int key, ctx *c);

int                 check_file_extension(char *filename);

int                 parse_file(char *map_file, ctx *c);

int					read_map(ctx *c);

void                print_error(int error_code);

void                move_up(ctx *c);

void                move_down(ctx *c);

void				move_right(ctx *c);

void				move_left(ctx *c);

int                 pick_random();

void			    put_pxl(ctx *c, int x, int y, unsigned int color);

//int                 get_key(int key, ctx *c);

void                exit_program(ctx *c, int error_code);

void				raycasting(ctx *c);

void				draw_line(ctx *c, int x, int wall_top, int wall_bottom);

int                 print_whole_screen(unsigned int color, ctx* c);

void 				adapt_screen_size(ctx *c);

#endif

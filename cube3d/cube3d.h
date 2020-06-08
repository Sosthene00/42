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

// All the mapping has been done on my AZERTY Ubuntu laptop, it might not work as expected
//# define KEY_UP 0x0077 //'w' on AZERTY keyboard
# define KEY_UP 0x007a //'z' on AZERTY keyboard
//# define KEY_LEFT 0x0061 //'a' on AZERTY
# define KEY_LEFT 0x0071 //'q' on AZERTY
# define KEY_RIGHT 0x0064
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

typedef	struct		context
{
    void            *mlx_ptr;
    void            *win_ptr;
    int             win_x;
    int             win_y;
    unsigned int    color_floor;
}					ctx;

ctx                 *init_ctx();

void                init_win(ctx *context);

int                 loop_hook(ctx *context);

int		            key_press(int key, ctx *context);

int                 key_release(int key, ctx *context);

int	                key_hook(int key, ctx *context);

int                 check_file_extension(char *filename);

int                 parse_map_file(char *map_file, ctx *context);

void                print_error(int error_code);

//int                 get_key(int key, ctx *context);

void                exit_program(ctx *context, int error_code);

int                 print_whole_screen(unsigned int color, ctx* context);

int                 is_in_screen_size(void *mlx_ptr, int x, int y);

#endif

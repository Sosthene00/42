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

# define WRONG_FILE "Something's wrong with the map file:\n"\
                    "Check that the file exists and its content is formatted correctly\n"
# define ERROR_PARSING "Error parsing map file content\n"
# define MEMORY_ERROR "Error while initializing mlx or malloc\n"

//typedef	struct		map_data
//{
//    int             x;
//    int             y;
//    char            *name;
//}					map;

typedef	struct		context
{
    void            *mlx_ptr;
    void            *win_ptr;
    int             win_x;
    int             win_y;
    char            *name;
}					ctx;

//map                 *init_map_data();

//mlx                 *init_mlx_data(map *map_data);

ctx                 *init_ctx();

void init_mlx(ctx *context);

int                 parse_map_file(char *map_file, ctx *context);

void                print_error(int error_code);

void                exit_program(ctx *context, int error_code);

//void                blue_screen(void *mlx_ptr, void *win_ptr, map *map_data);
int                 blue_screen(int key, ctx *context);

int                 is_in_screen_size(void *mlx_ptr, int x, int y);

#endif

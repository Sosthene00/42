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
# include "./mlx/mlx.h"
# include <math.h>

# define ONE_CHAR_IDENTIFIER "RSFC"
# define NORTH "NO"
# define SOUTH "SO"
# define EAST "EA"
# define WEST "WE"

# define WRONG_FILE "Non-existing or wrong map file, please check the file given as argument\n"

typedef	struct		map_data
{
    int             x;
    int             y;
    char            *name;
}					map;

int                 parse_map_file(char *map_file, map *map_data);

void                print_error(int error_code);

int                 exit_program(void *mlx_ptr, void *win_ptr, int error_code);

void                *init_win(void *mlx_ptr, map *map_data);

void                blue_screen(void *mlx_ptr, void *win_ptr, map *map_data);

#endif

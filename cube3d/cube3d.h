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

typedef	struct		map_data
{
    int             x;
    int             y;
    char            *name;
}					map;

typedef	struct		mlx_data
{
    void            *mlx_ptr;
    void            *win_ptr;
    map             map;
}					mlx;

map                 *init_map_data();

mlx                 *init_mlx_data(map *map_data);

int                 parse_map_file(char *map_file, map *map_data);

void                print_error(int error_code);

int                 exit_program(void *mlx_ptr, void *win_ptr, int error_code);

void                *init_win(void *mlx_ptr, map *map_data);

//void                blue_screen(void *mlx_ptr, void *win_ptr, map *map_data);
int                 blue_screen(mlx *mlx_data);

#endif

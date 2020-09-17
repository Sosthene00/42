/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:06:55 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/26 12:07:05 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_file_extension(char *filename)
{
	char **str;

	str = ft_split(filename, '.');
	if (str[1] != NULL)
	{
		if (!(ft_strncmp(str[1], FILE_EXT, 3)))
		{
			ft_freesplit(str);
			return (0);
		}
	}
	ft_freesplit(str);
	return (1);
}

void		adapt_screen_size(t_ctx *c)
{
	int *max_x;
	int *max_y;

	if (c->mlx_ptr == NULL)
		exit_program(c, MEMORY_ERROR);
	if ((!(max_x = malloc(sizeof(*max_x)))))
		exit_program(c, MEMORY_ERROR);
	if ((!(max_y = malloc(sizeof(*max_y)))))
		exit_program(c, MEMORY_ERROR);
	mlx_get_screen_size(c->mlx_ptr, max_x, max_y);
	if ((c->screen.width >= *max_x) || (c->screen.height >= *max_y))
	{
		c->screen.width = *max_x;
		c->screen.height = *max_y;
	}
	else if (c->screen.width < SCREEN_MIN_W || c->screen.height < SCREEN_MIN_H)
	{
		c->screen.width = SCREEN_MIN_W;
		c->screen.height = SCREEN_MIN_H;
	}
	free(max_x);
	free(max_y);
}

static void	init_ply(t_ctx *c)
{
	c->player.speed_move = 0.07;
	c->player.speed_turn = 0.02;
}

void		init_win(t_ctx *c)
{
	if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->screen.width, \
			c->screen.height, "Cub3d - Knee deep in Hell")))
		exit_program(c, 9);
}

void		init_img(t_ctx *c)
{
	c->screen.img_ptr = mlx_new_image(c->mlx_ptr, c->screen.width,
		c->screen.height);
	c->screen.data = mlx_get_data_addr(c->screen.img_ptr,
		&(c->screen.bpp), &(c->screen.size_line),
		&(c->screen.endianness));
}

t_ctx		*init_ctx(char *filename)
{
	t_ctx	*c;
	double	*zbuffer;
	int		error_code;

	if (!(c = ft_calloc(1, sizeof(*c))))
		exit_program(c, 9);
	if (!(c->mlx_ptr = mlx_init()))
		exit_program(c, 9);
	if ((error_code = parse_file(filename, c)) != 0)
		exit_program(c, error_code);
	init_ply(c);
	if (!(zbuffer = ft_calloc(c->screen.width, sizeof(*zbuffer))))
		exit_program(c, 9);
	c->ray.zbuffer = zbuffer;
	return (c);
}

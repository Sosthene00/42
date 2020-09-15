/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 14:15:07 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/26 14:15:10 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int				update_data(char **items, t_ctx *c)
{
	if (ft_memcmp(items[0], &"R", 2) == 0)
	{
		if (get_xy_value(items, c) == 0)
			return (0);
	}
	else if ((ft_memcmp(items[0], &"C", 2) == 0) ||
		(ft_memcmp(items[0], &"F", 2)) == 0)
	{
		if (get_color(items, c) == 0)
			return (0);
	}
	else if ((ft_memcmp(items[0], &"S", 2) == 0) ||
		(ft_strnstr(WALLS, items[0], ft_strlen(WALLS))))
	{
		if (extract_textures(items, c) == 0)
			return (0);
	}
	return (2);
}

int				is_complete(t_ctx *c)
{
	int params;

	params = EXPECTED_ARG;
	if (c->color.sky != 0 || c->skybox.img_ptr != 0)
		params--;
	if (c->color.floor != 0)
		params--;
	if (c->n_wall.img_ptr != 0)
		params--;
	if (c->w_wall.img_ptr != 0)
		params--;
	if (c->s_wall.img_ptr != 0)
		params--;
	if (c->e_wall.img_ptr != 0)
		params--;
	if (c->sprite.img_ptr != 0)
		params--;
	if (c->screen.width > 0)
		params--;
	return (params);
}

unsigned int	convert_color(int r, int g, int b)
{
	unsigned int color;

	if ((r < 0) || (r > 255) ||\
		(g < 0) || (g > 255) ||\
		(b < 0) || (b > 255))
		return (INT_MAX);
	color = (r << 16) + (g << 8) + b;
	return (color);
}

int				get_xy_value(char **val, t_ctx *c)
{
	if (c->screen.width != 0)
	{
		ft_putstr_fd(SCREEN_EXIST, 2);
		return (0);
	}
	if (!(val[1]) || !(val[2]) ||
			!(ft_isdigit(*val[1])) || !(ft_isdigit(*val[2])))
		return (2);
	c->screen.width = ft_atoi(val[1]);
	c->screen.height = ft_atoi(val[2]);
	adapt_screen_size(c);
	init_win(c);
	return (0);
}

int				get_color(char **items, t_ctx *c)
{
	char			**val;
	unsigned int	color;

	val = ft_split(items[1], ',');
	if (!(val[0]) || !(val[1]) || !(val[2]) || \
		!(ft_isdigit(*val[0])) || !(ft_isdigit(*val[1])) ||
		!(ft_isdigit(*val[2])))
		return (2);
	color = convert_color(ft_atoi(val[0]), ft_atoi(val[1]), ft_atoi(val[2]));
	ft_freesplit(val);
	if (color == INT_MAX)
		return (2);
	if ((items[0][0] == 'C') && (c->color.sky == 0))
		c->color.sky = color;
	else if ((items[0][0] == 'F') && (c->color.floor == 0))
		c->color.floor = color;
	else
		ft_putstr_fd(COLOR_EXIST, 2);
	return (0);
}

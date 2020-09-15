/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:05:02 by agaubert          #+#    #+#             */
/*   Updated: 2020/09/01 15:05:05 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void			put_pxl(t_ima *screen, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * screen->size_line);
	*(unsigned int*)(screen->data + i) = color;
}

unsigned int	extract_color(t_ctx *c, t_ima *texture)
{
	unsigned int	color;
	int				i;

	i = (c->ray.tex_x * 4) + (c->ray.tex_y * texture->size_line);
	color = *(unsigned int*)(texture->data + i);
	return (color);
}

static int		draw_walls(t_ctx *c, t_ima *texture, int x, int y)
{
	int				d;
	unsigned int	color;

	calc_tex_x(c, texture);
	while (y < c->ray.wall_bottom)
	{
		d = y * 256 - c->screen.height * 128 + c->ray.wall_height * 128;
		c->ray.tex_y = ((d * texture->height) / c->ray.wall_height) / 256;
		color = extract_color(c, texture);
		put_pxl(&(c->screen), x, y, color);
		y++;
	}
	return (y);
}

void			draw_sprite(t_ctx *c, t_ima *texture)
{
	t_ima	*temp;
	t_sprt	*sprite;
	int		i;

	i = -1;
	while (++i < texture->amt)
	{
		temp = texture;
		while (temp->order != i)
			temp = temp->next;
		sprite = init_sprite(c, temp);
		get_values(c, sprite);
		draw_stripes(c, texture, sprite);
		free(sprite);
	}
}

void			draw_line(t_ctx *c, t_ima *texture, int x)
{
	int	y;

	y = -1;
	while (++y < c->ray.wall_top)
	{
		if (c->skybox.img_ptr != 0)
		{
			c->ray.tex_x = x;
			c->ray.tex_y = y;
			put_pxl(&(c->screen), x, y, extract_color(c, &(c->skybox)));
		}
		else
			put_pxl(&(c->screen), x, y, c->color.sky);
	}
	y = draw_walls(c, texture, x, y);
	while (++y < c->screen.height)
	{
		put_pxl(&(c->screen), x, y, c->color.floor);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:52:46 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:52:50 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_values(t_ctx *c, t_sprt *s)
{
	s->transform_x = s->inv_det * (c->player.dir.y *
		s->sprite_x - c->player.dir.x * s->sprite_y);
	s->transform_y = s->inv_det * (-(c->player.plane.y) *
		s->sprite_x + c->player.plane.x * s->sprite_y);
	s->screen_x = (int)((c->screen.width / 2) *
		(1 + s->transform_x / s->transform_y));
	s->vmove_screen = (int)(VMOVE / s->transform_y);
	s->height = abs((int)(c->screen.height / (s->transform_y))) / VDIV;
	s->draw_start_y = -(s->height) / 2 + c->screen.height / 2 + s->vmove_screen;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->height / 2 + c->screen.height / 2 + s->vmove_screen;
	if (s->draw_end_y >= c->screen.height)
		s->draw_end_y = c->screen.height - 1;
	s->width = abs((int)(c->screen.height / s->transform_y)) / UDIV;
	s->draw_start_x = -(s->width) / 2 + s->screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->width / 2 + s->screen_x;
	if (s->draw_end_x >= c->screen.width)
		s->draw_end_x = c->screen.width - 1;
}

void	draw_stripes(t_ctx *c, t_img *texture, t_sprt *s)
{
	int				stripe;
	int				y;
	int				d;
	unsigned int	color;

	stripe = s->draw_start_x - 1;
	while (++stripe < s->draw_end_x)
	{
		c->ray.tex_x = (int)(256 * (stripe - (-(s->width) / 2 + s->screen_x)) *
			c->sprite.width / s->width) / 256;
		if (s->transform_y > 0 && stripe > 0 && stripe < c->screen.width &&
			s->transform_y < c->ray.zbuffer[stripe])
		{
			y = s->draw_start_y;
			while (y < s->draw_end_y)
			{
				d = (y - s->vmove_screen) * 256 - c->screen.height * 128 +
					s->height * 128;
				c->ray.tex_y = ((d * c->sprite.height) / s->height) / 256;
				if ((color = extract_color(c, texture) & 0x00FFFFFF) != 0)
					put_pxl(&(c->screen), stripe, y, color);
				y++;
			}
		}
	}
}

t_sprt	*init_sprite(t_ctx *c, t_img *texture)
{
	t_sprt *sprite_data;

	if (!(sprite_data = ft_calloc(1, sizeof((*sprite_data)))))
		exit_program(c, 9);
	sprite_data->sprite_x = texture->map_x - c->player.pos.x;
	sprite_data->sprite_y = texture->map_y - c->player.pos.y;
	sprite_data->inv_det = 1.0 / (c->player.plane.x * c->player.dir.y -
		c->player.dir.x * c->player.plane.y);
	return (sprite_data);
}

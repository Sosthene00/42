/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:56:51 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:56:54 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ray_draw(t_ctx *c, int x)
{
	t_img		*texture;

	c->ray.wall_height = (int)floor(c->screen.height / c->ray.dist);
	c->ray.wall_top = -c->ray.wall_height / 2 + c->screen.height / 2;
	if (c->ray.wall_top < 0)
		c->ray.wall_top = 0;
	c->ray.wall_bottom = c->ray.wall_height / 2 + c->screen.height / 2;
	if (c->ray.wall_bottom >= c->screen.height)
		c->ray.wall_bottom = c->screen.height - 1;
	texture = wall_orientation(c);
	draw_line(c, texture, x);
}

static void		update_dist(t_ctx *c)
{
	if (c->ray.hit_side == 0)
		c->ray.dist = (c->ray.map.x - c->ray.pos.x +
			(1 - c->ray.step.x) / 2) / c->ray.dir.x;
	else
		c->ray.dist = (c->ray.map.y - c->ray.pos.y +
			(1 - c->ray.step.y) / 2) / c->ray.dir.y;
}

static void		ray_cal_dist(t_ctx *c)
{
	while (c->ray.hit == 0)
	{
		if (c->ray.side.x < c->ray.side.y)
		{
			c->ray.side.x += c->ray.delta.x;
			c->ray.map.x += c->ray.step.x;
			c->ray.hit_side = 0;
		}
		else
		{
			c->ray.side.y += c->ray.delta.y;
			c->ray.map.y += c->ray.step.y;
			c->ray.hit_side = 1;
		}
		if (c->map[c->ray.map.x][c->ray.map.y] == '1' ||
			c->map[c->ray.map.x][c->ray.map.y] == '3')
		{
			c->ray.hit = 1;
			update_dist(c);
		}
	}
}

static void		ray_init(t_ctx *c, int x)
{
	c->ray.pos.x = c->player.pos.x;
	c->ray.pos.y = c->player.pos.y;
	c->ray.map.x = (int)c->ray.pos.x;
	c->ray.map.y = (int)c->ray.pos.y;
	c->ray.cam = 2.0 * (double)x / (double)c->screen.width - 1.0;
	c->ray.dir.x = c->player.dir.x + c->player.plane.x * c->ray.cam;
	c->ray.dir.y = c->player.dir.y + c->player.plane.y * c->ray.cam;
	c->ray.delta.x = sqrt(1 + (pow(c->ray.dir.y, 2) / (pow(c->ray.dir.x, 2))));
	c->ray.delta.y = sqrt(1 + (pow(c->ray.dir.x, 2) / (pow(c->ray.dir.y, 2))));
	c->ray.hit = 0;
	c->ray.dist = -1;
	c->ray.hit_side = 0;
	c->ray.step.x = (c->ray.dir.x < 0) ? -1 : 1;
	c->ray.step.y = (c->ray.dir.y < 0) ? -1 : 1;
	c->ray.side.x = (c->ray.dir.x < 0) ?
		(c->ray.pos.x - c->ray.map.x) * c->ray.delta.x :
		(c->ray.map.x - c->ray.pos.x + 1) * c->ray.delta.x;
	c->ray.side.y = (c->ray.dir.y < 0) ?
		(c->ray.pos.y - c->ray.map.y) * c->ray.delta.y :
		(c->ray.map.y - c->ray.pos.y + 1) * c->ray.delta.y;
}

void			raycasting(t_ctx *c)
{
	int		x;

	x = -1;
	while (++x < c->screen.width)
	{
		ray_init(c, x);
		ray_cal_dist(c);
		c->ray.zbuffer[x] = c->ray.dist;
		ray_draw(c, x);
	}
	order_sprite_dist(c, &(c->sprite));
	draw_sprite(c, &(c->sprite));
}

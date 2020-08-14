#include "cube3d.h"

static void		ray_draw(ctx *c, int x)
{
	int		height;
	int		wall_top;
	int		wall_bottom;
	img		*texture;

	height = (int)(c->screen.height / c->ray.dist);
	wall_top = -height / 2 + c->screen.height / 2;
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = height / 2 + c->screen.height / 2;
	if (wall_bottom >= c->screen.height)
		wall_bottom = c->screen.height - 1;
	texture = wall_orientation(c);
	draw_line(c, texture, x, wall_top, wall_bottom);
}

static void		ray_cal_dist(ctx *c)
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
		if (c->map[c->ray.map.x][c->ray.map.y] > '0')
		{
			c->ray.hit = 1;
			if (c->ray.hit_side == 0)
				c->ray.dist = (c->ray.map.x - c->ray.pos.x + (1 - c->ray.step.x) / 2) / c->ray.dir.x;
			else
				c->ray.dist = (c->ray.map.y - c->ray.pos.y + (1 - c->ray.step.y) / 2) / c->ray.dir.y;
		}
	}
}

static void		ray_cal_step_side(ctx *c)
{
	if (c->ray.dir.x < 0)
	{
		c->ray.step.x = -1;
		c->ray.side.x = (c->ray.pos.x - c->ray.map.x) * c->ray.delta.x;
	}
	else
	{
		c->ray.step.x = 1;
		c->ray.side.x = (c->ray.map.x + 1 - c->ray.pos.x) * c->ray.delta.x;
	}
	if (c->ray.dir.y < 0)
	{
		c->ray.step.y = -1;
		c->ray.side.y = (c->ray.pos.y - c->ray.map.y) * c->ray.delta.y;
	}
	else
	{
		c->ray.step.y = 1;
		c->ray.side.y = (c->ray.map.y + 1 - c->ray.pos.y) * c->ray.delta.y;
	}
}

static void		ray_init(ctx *c, int x)
{
	c->ray.pos.x = c->player.pos.x;
	c->ray.pos.y = c->player.pos.y;
	c->ray.map.x = (int)c->ray.pos.x;
	c->ray.map.y = (int)c->ray.pos.y;
	c->ray.cam = 2 * x / (double)c->screen.width - 1;
	c->ray.dir.x = c->player.dir.x + c->player.plane.x * c->ray.cam;
	c->ray.dir.y = c->player.dir.y + c->player.plane.y * c->ray.cam;
	c->ray.delta.x = sqrt(1 + (pow(c->ray.dir.y, 2) / (pow(c->ray.dir.x, 2))));
	c->ray.delta.y = sqrt(1 + (pow(c->ray.dir.x, 2) / (pow(c->ray.dir.y, 2))));
	c->ray.hit = 0;
	c->ray.dist = -1;
	c->ray.hit_side = 0;
}

void			raycasting(ctx *c)
{
	int		x;

	x = -1;
	while (++x < c->screen.width)
	{
		ray_init(c, x);
		ray_cal_step_side(c);
		ray_cal_dist(c);
		c->ray.zbuffer[x] = c->ray.dist;
		ray_draw(c, x);
	}
	order_sprite_dist(c, &(c->sprite));
	draw_sprite(c, &(c->sprite));
}

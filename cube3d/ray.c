#include "cube3d.h"

static void		ray_draw(ctx *context, int x)
{
	int		height;
	int		wall_top;
	int		wall_bottom;

	height = (int)(context->win_y / context->ray.dist);
	wall_top = -height / 2 + context->win_y / 2;
	if (wall_top < 0)
		wall_top = 0;
	wall_bottom = height / 2 + context->win_y / 2;
	if (wall_bottom >= context->win_y)
		wall_bottom = context->win_y - 1;
	draw_line(context, x, wall_top, wall_bottom);
}

static void		ray_cal_dist(ctx *context)
{
	while (context->ray.hit == 0)
	{
		if (context->ray.side.x < context->ray.side.y)
		{
			context->ray.side.x += context->ray.delta.x;
			context->ray.map.x += context->ray.step.x;
			context->ray.hit_side = 0;
		}
		else
		{
			context->ray.side.y += context->ray.delta.y;
			context->ray.map.y += context->ray.step.y;
			context->ray.hit_side = 1;
		}
		if (context->map[context->ray.map.x][context->ray.map.y] != '0')
		{
			context->ray.hit = 1;
			if (context->ray.hit_side == 0)
				context->ray.dist = (context->ray.map.x - context->ray.pos.x + (1 - context->ray.step.x) / 2) / context->ray.dir.x;
			else
				context->ray.dist = (context->ray.map.y - context->ray.pos.y + (1 - context->ray.step.y) / 2) / context->ray.dir.y;
		}
	}
}

static void		ray_cal_step_side(ctx *context)
{
	if (context->ray.dir.x < 0)
	{
		context->ray.step.x = -1;
		context->ray.side.x = (context->ray.pos.x - context->ray.map.x) * context->ray.delta.x;
	}
	else
	{
		context->ray.step.x = 1;
		context->ray.side.x = (context->ray.map.x + 1 - context->ray.pos.x) * context->ray.delta.x;
	}
	if (context->ray.dir.y < 0)
	{
		context->ray.step.y = -1;
		context->ray.side.y = (context->ray.pos.y - context->ray.map.y) * context->ray.delta.y;
	}
	else
	{
		context->ray.step.y = 1;
		context->ray.side.y = (context->ray.map.y + 1 - context->ray.pos.y) * context->ray.delta.y;
	}
}

static void		ray_init(ctx *context, int x)
{
	context->ray.map.x = (int)context->ray.pos.x;
	context->ray.map.y = (int)context->ray.pos.y;
	context->ray.cam = 2 * x / (double)context->win_x - 1;
	context->ray.dir.x = context->player.dir.x + context->player.plane.x * context->ray.cam;
	context->ray.dir.y = context->player.dir.y + context->player.plane.y * context->ray.cam;
	if (context->ray.dir.y == 0)
		context->ray.delta.x = 0;
	else
		context->ray.delta.x = (context->ray.dir.x == 0) ? 1 : abs(1 / context->ray.dir.x);
	if (context->ray.dir.x == 0)
		context->ray.delta.y = 0;
	else
		context->ray.delta.y = (context->ray.dir.y == 0) ? 1 : abs(1 / context->ray.dir.y);
	context->ray.hit = 0;
	context->ray.dist = -1;
	context->ray.hit_side = 0;
}

void			raycasting(ctx *context)
{
	int		x;

	x = -1;
	context->ray.pos.x = context->player.pos.x;
	context->ray.pos.y = context->player.pos.y;
	while (++x < context->win_y)
	{
		ray_init(context, x);
		ray_cal_step_side(context);
		ray_cal_dist(context);
		ray_draw(context, x);
	}
}

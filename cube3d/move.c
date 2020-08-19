#include "cube3d.h"

void	move_up(ctx *c)
{
	if (c->map[(int)(c->player.pos.x + c->player.dir.x * c->player.speed_move)]
		[(int)c->player.pos.y] == '0')
		c->player.pos.x += c->player.dir.x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][(int)(c->player.pos.y + c->player.dir.y *
			c->player.speed_move)] == '0')
		c->player.pos.y += c->player.dir.y * c->player.speed_move;
}

void	move_down(ctx *c)
{
	if (c->map[(int)(c->player.pos.x - c->player.dir.x * c->player.speed_move)]
			[(int)c->player.pos.y] == '0')
		c->player.pos.x -= c->player.dir.x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][(int)(c->player.pos.y - c->player.dir.y *
			c->player.speed_move)] == '0')
		c->player.pos.y -= c->player.dir.y * c->player.speed_move;
}

void	move_right(ctx *c)
{
	dxy	old;

	old.x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(-c->player.speed_turn) -
		c->player.dir.y * sin(-(c->player.speed_turn));
	c->player.dir.y = old.x * sin(-(c->player.speed_turn)) +
		c->player.dir.y * cos(-(c->player.speed_turn));
	old.x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(-(c->player.speed_turn)) -
		c->player.plane.y * sin(-(c->player.speed_turn));
	c->player.plane.y = old.x * sin(-(c->player.speed_turn)) +
		c->player.plane.y * cos(-(c->player.speed_turn));
}

void	move_left(ctx *c)
{
	dxy	old;

	old.x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(c->player.speed_turn) -
		c->player.dir.y * sin(c->player.speed_turn);
	c->player.dir.y = old.x * sin(c->player.speed_turn) +
		c->player.dir.y * cos(c->player.speed_turn);
	old.x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(c->player.speed_turn) -
		c->player.plane.y * sin(c->player.speed_turn);
	c->player.plane.y = old.x * sin(c->player.speed_turn) +
		c->player.plane.y * cos(c->player.speed_turn);
}

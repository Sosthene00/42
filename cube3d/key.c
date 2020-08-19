#include "cube3d.h"

int	key_press(int key, ctx *c)
{
	if (key == KEY_UP)
		c->player.move_up = 1;
	if (key == KEY_DOWN)
		c->player.move_down = 1;
	if (key == KEY_RIGHT)
		c->player.move_right = 1;
	if (key == KEY_LEFT)
		c->player.move_left = 1;
	if (key == KEY_ESC)
		exit_program(c, 0);
	return (0);
}

int	key_release(int key, ctx *c)
{
	if (key == KEY_UP)
		c->player.move_up = 0;
	if (key == KEY_DOWN)
		c->player.move_down = 0;
	if (key == KEY_RIGHT)
		c->player.move_right = 0;
	if (key == KEY_LEFT)
		c->player.move_left = 0;
	return (0);
}

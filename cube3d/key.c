#include "cube3d.h"

int key_press(int key, ctx *context)
{
	if (key == KEY_UP)
		context->player.move_up = 1;
	if (key == KEY_DOWN)
		context->player.move_down = 1;
	if (key == KEY_ESC)
        exit_program(context, 0);
    return (0);
}

int	key_release(int key, ctx *context)
{
	if (key == KEY_UP)
		context->player.move_up = 0;
	if (key == KEY_DOWN)
		context->player.move_down = 0;
	return (0);
}

/*int		key_hook(int key, ctx *context)
{
	get_key(key, context);
	return (0);
}*/
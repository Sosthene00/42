#include "cube3d.h"

int key_press(int key, ctx *context)
{
	unsigned int	color;

	if (key == KEY_UP)
        print_whole_screen(color=pick_random(), context);
	if (key == KEY_DOWN)
        print_whole_screen(color=0x000001, context);
	if (key == KEY_ESC)
        exit_program(context, 0);
    return (0);
}

int	key_release(int key, ctx *context)
{
	unsigned int	color;

	if (key == KEY_DOWN)
        print_whole_screen(color=0xffffff, context);
	return (0);
}

/*int		key_hook(int key, ctx *context)
{
	get_key(key, context);
	return (0);
}*/
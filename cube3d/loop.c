#include "cube3d.h"

int		loop_hook(ctx *c)
{
	if (c->player.move_up)
		move_up(c);
	if (c->player.move_down)
		move_down(c);
	if (c->player.move_right)
		move_right(c);
	if (c->player.move_left)
		move_left(c);
	raycasting(c);
	if (c->screenshot == 1)
		save_screenshot(c);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->screen.img_ptr, 0, 0);
	mlx_do_sync(c->mlx_ptr);
    return (0);
}
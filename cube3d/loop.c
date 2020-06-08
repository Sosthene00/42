#include "cube3d.h"

int		loop_hook(ctx *context)
{
	/*e->mlx.last_frame = clock();
	if (e->mlx.next_frame > e->mlx.last_frame)
		return (0);
	e->mlx.next_frame = e->mlx.last_frame + (CLOCKS_PER_SEC / 100);*/
	if (context->player.move_up)
		move_up(context);
	if (context->player.move_down)
		move_down(context);
	/*if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	if (e->player.move_jump == 1)
		move_jump(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);*/
	mlx_put_image_to_window(context->mlx_ptr, context->win_ptr, context->img, 0, 0);
    return (0);
}
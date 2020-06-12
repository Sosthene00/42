#include "cube3d.h"

int		loop_hook(ctx *context)
{
	if (context->player.move_up)
		move_up(context);
	if (context->player.move_down)
		move_down(context);
	if (!(context->player.move_up) && !(context->player.move_down))
		stop(context);
	raycasting(context);
	mlx_put_image_to_window(context->mlx_ptr, context->win_ptr, context->img, 0, 0);
    return (0);
}
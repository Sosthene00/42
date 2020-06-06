#include "cube3d.h"

int		loop_hook(ctx *context)
{
	/*e->mlx.last_frame = clock();
	if (e->mlx.next_frame > e->mlx.last_frame)
		return (0);
	e->mlx.next_frame = e->mlx.last_frame + (CLOCKS_PER_SEC / 100);
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	if (e->player.move_jump == 1)
		move_jump(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);*/
    if (context->color_floor != 0)
        print_whole_screen(context->color_floor, context);
    return (0);
}
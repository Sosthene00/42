#include "./cube3d.h"

int blue_screen(int key, ctx *context)
{
    int i;
    int j;

	(void)key;
    i = -1;
    j = -1;
	while (++i < context->win_x)
	{
		while (++j < context->win_y)
		{
			mlx_pixel_put(context->mlx_ptr, context->win_ptr, i, j, 254);
		}
		j = -1;
	}
    return (0);
}
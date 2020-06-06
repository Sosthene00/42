#include "./cube3d.h"

int pick_random()
{
	int i, n;

	srand(time(NULL));
    for (i = 0; i < 3; )
	{
        if ((n = rand()) > 0 && n < pow(2, 24))
			i++;
	}
    return n;
}

int print_whole_screen(unsigned int color, ctx* context)
{
    int i;
    int j;

    i = -1;
    j = -1;
	if (color == 0)
		color = pick_random();
	while (++i < context->win_x)
	{
		while (++j < context->win_y)
		{
			mlx_pixel_put(context->mlx_ptr, context->win_ptr, i, j, color);
		}
		j = -1;
	}
    return (0);
}

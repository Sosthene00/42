#include "./cube3d.h"

void			put_pxl(ctx *context, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * context->s_line);
	context->pxl[i] = c;
	context->pxl[++i] = c >> 8;
	context->pxl[++i] = c >> 16;
}

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
			put_pxl(context, i, j, color);
		}
		j = -1;
	}
    return (0);
}

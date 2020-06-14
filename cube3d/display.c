#include "./cube3d.h"

void			put_pxl(ctx *c, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * c->size_line);
	c->pxl[i] = color;
	c->pxl[++i] = color >> 8;
	c->pxl[++i] = color >> 16;
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

int print_whole_screen(unsigned int color, ctx* c)
{
    int i;
    int j;

    i = -1;
    j = -1;
	if (color == 0)
		color = pick_random();
	while (++i < c->win_x)
	{
		while (++j < c->win_y)
		{
			put_pxl(c, i, j, color);
		}
		j = -1;
	}
    return (0);
}

void    draw_line(ctx *c, int x, int wall_top, int wall_bottom)
{
	int i;

	i = -1;
	while (++i < wall_top + c->player.z)
		put_pxl(c, x, i, c->color.sky);
	while (++i < wall_bottom + c->player.z)
		put_pxl(c, x, i, 0x010101);
	while (++i < c->win_y)
		put_pxl(c, x, i, c->color.floor);
}

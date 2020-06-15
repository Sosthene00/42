#include "./cube3d.h"

void			put_pxl(img img, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * img.size_line);
	img.data[i] = color;
	img.data[++i] = color >> 8;
	img.data[++i] = color >> 16;
}

void    draw_line(ctx *c, int x, int wall_top, int wall_bottom)
{
	int i;

	i = -1;
	while (++i < wall_top + c->player.z)
		put_pxl(c->screen, x, i, c->color.sky);
	while (++i < wall_bottom + c->player.z)
		put_pxl(c->screen, x, i, 0x010101);
	while (++i < c->win_y)
		put_pxl(c->screen, x, i, c->color.floor);
}

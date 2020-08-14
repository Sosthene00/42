#include "./cube3d.h"

void			put_pxl(img *img, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * img->size_line);
	img->data[i] = color;
	img->data[++i] = color >> 8;
	img->data[++i] = color >> 16;
}

unsigned int extract_color(ctx *c, img *texture)
{
	unsigned int color;
	char	*buffer;
	int		i;

	i = (c->ray.tex_x * 4) + (c->ray.tex_y * texture->size_line);
	if ((buffer = malloc(sizeof(unsigned int))) == NULL)
		exit_program(c, 9);	
	ft_memcpy(buffer, (texture->data + i), sizeof(unsigned int));
	color = *(unsigned int*)(buffer);
	free(buffer);
	return (color);
}

int	draw_texture(ctx *c, img *texture, int x, int y, int drawEnd)
{
	double 			step;
	int				lineHeight;
	//int				d;
	unsigned int 	color;
	double			texPos;

	lineHeight = drawEnd - y;
	calc_tex_x(c, texture);
	step = (double)texture->height / lineHeight;
	texPos = (y - c->screen.height / 2 + lineHeight / 2) * step;
	while (y < drawEnd)
	{
		//d = y * 256 - c->screen.height * 128 + lineHeight * 128;
		//c->ray.tex_y = ((d * texture->height) / lineHeight) / 256;
		c->ray.tex_y = (int)texPos & (texture->height - 1);
		texPos += step;
		color = extract_color(c, texture);
		put_pxl(&(c->screen), x, y, color);
		y++;
	}
	return (y);
}

void	draw_sprite(ctx *c, img *texture)
{
	img		*temp;
	sprt	*sprite;
	int 	i;

	i = -1;
	while (++i < texture->amt)
	{
		temp = texture;
		while (temp->order != i)
			temp = temp->next;
		sprite = init_sprite(c, temp);
		get_values(c, sprite);
		draw_stripes(c, texture, sprite);
		free(sprite);
    }
}

void    draw_line(ctx *c, img *texture, int x, int wall_top, int wall_bottom)
{
	int y;

	y = -1;
	while (++y < wall_top)
		put_pxl(&(c->screen), x, y, c->color.sky);
	y = draw_texture(c, texture, x, y, wall_bottom);
	while (++y < c->screen.height)
		put_pxl(&(c->screen), x, y, c->color.floor);
}

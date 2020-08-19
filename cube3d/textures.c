#include "cube3d.h"

void	calc_tex_x(ctx *c, img *tex)
{
	if (c->ray.hit_side == 0)
		c->ray.wall_x = c->ray.pos.y + c->ray.dist * c->ray.dir.y;
	else
		c->ray.wall_x = c->ray.pos.x + c->ray.dist * c->ray.dir.x;
	c->ray.wall_x -= floor(c->ray.wall_x);
	c->ray.tex_x = (int)(c->ray.wall_x * (double)(tex->width));
	c->ray.tex_x = tex->width - c->ray.tex_x - 1;
}

img		*wall_orientation(ctx *c)
{
	if ((c->ray.hit_side == 0) && (c->ray.step.x == -1))
		return (&(c->N_wall));
	else if ((c->ray.hit_side == 0) && (c->ray.step.x == 1))
		return (&(c->S_wall));
	else if ((c->ray.hit_side == 1) && (c->ray.step.y == -1))
		return (&(c->W_wall));
	else if ((c->ray.hit_side == 1) && (c->ray.step.y == 1))
		return (&(c->E_wall));
	return (NULL);
}

int		init_texture(img *txt, char *filename, ctx *c)
{
	if (!(txt->img_ptr = mlx_xpm_file_to_image(c->mlx_ptr, filename,
		&(txt->width), &(txt->height))))
		return (2);
	txt->data = mlx_get_data_addr(txt->img_ptr,
		&(txt->bits_per_pixel), &(txt->size_line), &(txt->endianness));
	return (0);
}

int		extract_textures(char **items, ctx *c)
{
	if (ft_strncmp(items[0], "NO", 2) == 0)
		return (init_texture(&(c->N_wall), items[1], c));
	else if (ft_strncmp(items[0], "SO", 2) == 0)
		return (init_texture(&(c->S_wall), items[1], c));
	else if (ft_strncmp(items[0], "WE", 2) == 0)
		return (init_texture(&(c->W_wall), items[1], c));
	else if (ft_strncmp(items[0], "EA", 2) == 0)
		return (init_texture(&(c->E_wall), items[1], c));
	else if (ft_strncmp(items[0], "S", 1) == 0)
		return (init_texture(&(c->sprite), items[1], c));
	return (2);
}

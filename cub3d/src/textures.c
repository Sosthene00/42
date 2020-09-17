/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:00:23 by agaubert          #+#    #+#             */
/*   Updated: 2020/09/01 15:00:25 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_tex_x(t_ctx *c, t_ima *tex)
{
	if (c->ray.hit_side == 0)
		c->ray.wall_x = c->ray.pos.y + c->ray.dist * c->ray.dir.y;
	else
		c->ray.wall_x = c->ray.pos.x + c->ray.dist * c->ray.dir.x;
	c->ray.wall_x -= floor(c->ray.wall_x);
	c->ray.tex_x = (int)(c->ray.wall_x * (double)(tex->width));
	c->ray.tex_x = tex->width - c->ray.tex_x - 1;
}

t_ima	*wall_orientation(t_ctx *c)
{
	if ((c->ray.hit_side == 0) && (c->ray.step.x == -1))
		return (&(c->n_wall));
	else if ((c->ray.hit_side == 0) && (c->ray.step.x == 1))
		return (&(c->s_wall));
	else if ((c->ray.hit_side == 1) && (c->ray.step.y == -1))
		return (&(c->w_wall));
	else if ((c->ray.hit_side == 1) && (c->ray.step.y == 1))
		return (&(c->e_wall));
	return (NULL);
}

int		init_texture(t_ima *txt, char *filename, t_ctx *c)
{
	if (!(txt->img_ptr = mlx_xpm_file_to_image(c->mlx_ptr, filename,
		&(txt->width), &(txt->height))))
		return (2);
	txt->data = mlx_get_data_addr(txt->img_ptr,
		&(txt->bpp), &(txt->size_line), &(txt->endianness));
	return (0);
}

int		extract_textures(char **items, t_ctx *c)
{
	if (ft_strncmp(items[0], "NO", 2) == 0)
		return (init_texture(&(c->n_wall), items[1], c));
	else if (ft_strncmp(items[0], "SO", 2) == 0)
		return (init_texture(&(c->s_wall), items[1], c));
	else if (ft_strncmp(items[0], "WE", 2) == 0)
		return (init_texture(&(c->w_wall), items[1], c));
	else if (ft_strncmp(items[0], "EA", 2) == 0)
		return (init_texture(&(c->e_wall), items[1], c));
	else if (ft_strncmp(items[0], "S", 1) == 0)
		return (init_texture(&(c->sprite), items[1], c));
	return (2);
}

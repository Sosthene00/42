/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:52:35 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:52:38 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_terminate(void *mlxptr)
{
	struct s_xvar	*xvar;

	xvar = mlxptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}

static void free_mlx_img(t_ctx *c)
{
	if (c->sprite.img_ptr)
	{
		mlx_destroy_image(c->mlx_ptr, c->sprite.img_ptr);
		free(c->sprite.img_ptr);
	}
	if (c->s_wall.img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->s_wall.img_ptr);
	if (c->n_wall.img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->n_wall.img_ptr);
	if (c->e_wall.img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->e_wall.img_ptr);
	if (c->w_wall.img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->w_wall.img_ptr);
	if (c->screen.img_ptr)
		mlx_destroy_image(c->mlx_ptr, c->screen.img_ptr);
}

static void	free_sprite_list(t_ima head)
{
	t_ima *cur;
	t_ima *next;

	cur = head.next;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

static void	free_context(t_ctx *c)
{
	if (c->ray.zbuffer)
		free(c->ray.zbuffer);
	if (c->sprite.next)
		free_sprite_list(c->sprite);
	if (c->map)
		ft_freesplit(c->map);
	free_mlx_img(c);
	if (c->win_ptr)
	{
		free(c->win_ptr);
	}
	if (c->mlx_ptr)
	{
		mlx_terminate(c->mlx_ptr);
		//free(c->mlx_ptr);
	}
	if (c)
		free(c);
}

void		free_all(t_ctx *c)
{
	free_context(c);
}

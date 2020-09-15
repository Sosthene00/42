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

static void	free_sprite_list(t_img head)
{
	t_img *cur;
	t_img *next;

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
	if (c)
		free(c);
}

void		free_all(t_ctx *c)
{
	free_context(c);
}

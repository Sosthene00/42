/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:57:07 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:57:19 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_sprite_to_list(t_img **alst, t_img *new)
{
	t_img	*temp;

	temp = *alst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
	new->order = temp->order + 1;
	temp = *alst;
	temp->amt = new->order + 1;
}

int			update_sprite(t_ctx *c, int x, int y)
{
	t_img *texture;
	t_img *root;

	root = &(c->sprite);
	if (root->map_x == 0)
	{
		root->map_x = ((double)x + 0.5);
		root->map_y = ((double)y + 0.5);
		return (0);
	}
	else
	{
		if (!(texture = ft_calloc(1, sizeof(*texture))))
			exit_program(c, 9);
		texture->map_x = ((double)x + 0.5);
		texture->map_y = ((double)y + 0.5);
		add_sprite_to_list(&root, texture);
	}
	return (0);
}

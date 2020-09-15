/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:57:25 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:57:27 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void		swap_order(t_img *a, t_img *b)
{
	int c;

	c = a->order;
	a->order = b->order;
	b->order = c;
}

static t_img	*go_to_order(t_img *sprite, int n)
{
	t_img *temp;

	temp = sprite;
	while (temp->order != n)
		temp = temp->next;
	return (temp);
}

static void		bubblesort(t_img *sprite)
{
	int		i;
	int		j;
	t_img	*a;
	t_img	*b;

	i = -1;
	while (++i < (sprite->amt))
	{
		j = -1;
		while (++j < (sprite->amt) - i - 1)
		{
			a = go_to_order(sprite, j);
			b = go_to_order(sprite, j + 1);
			if (a->distance < b->distance)
				swap_order(a, b);
		}
	}
}

void			order_sprite_dist(t_ctx *c, t_img *sprite)
{
	t_img	*temp;
	int		count;

	count = 0;
	temp = sprite;
	while (temp)
	{
		temp->distance = (pow(c->player.pos.x - temp->map_x, 2) +
			pow(c->player.pos.y - temp->map_y, 2));
		temp->order = count;
		temp = temp->next;
		count++;
	}
	bubblesort(sprite);
}

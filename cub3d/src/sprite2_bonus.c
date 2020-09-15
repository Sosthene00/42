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

static void		swap_order(t_ima *a, t_ima *b)
{
	int c;

	c = a->order;
	a->order = b->order;
	b->order = c;
}

static t_ima	*go_to_order(t_ima *sprite, int n)
{
	t_ima *temp;

	temp = sprite;
	while (temp->order != n)
		temp = temp->next;
	return (temp);
}

static void		bubblesort(t_ima *sprite)
{
	int		i;
	int		j;
	t_ima	*a;
	t_ima	*b;

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

void			order_sprite_dist(t_ctx *c, t_ima *sprite)
{
	t_ima	*temp;
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

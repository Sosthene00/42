/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:55:17 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:55:19 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_up(t_ctx *c)
{
	int new_x;
	int new_y;

	new_x = (int)(c->player.pos.x + c->player.dir.x * c->player.speed_move);
	new_y = (int)(c->player.pos.y + c->player.dir.y * c->player.speed_move);
	if (c->map[new_x][(int)c->player.pos.y] == '0')
		c->player.pos.x += c->player.dir.x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][new_y] == '0')
		c->player.pos.y += c->player.dir.y * c->player.speed_move;
}

void	move_down(t_ctx *c)
{
	int new_x;
	int new_y;

	new_x = (int)(c->player.pos.x - c->player.dir.x * c->player.speed_move);
	new_y = (int)(c->player.pos.y - c->player.dir.y * c->player.speed_move);
	if (c->map[new_x][(int)c->player.pos.y] == '0')
		c->player.pos.x -= c->player.dir.x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][new_y] == '0')
		c->player.pos.y -= c->player.dir.y * c->player.speed_move;
}

void	move_right(t_ctx *c)
{
	t_dxy	old;

	old.x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(-c->player.speed_turn) -
		c->player.dir.y * sin(-(c->player.speed_turn));
	c->player.dir.y = old.x * sin(-(c->player.speed_turn)) +
		c->player.dir.y * cos(-(c->player.speed_turn));
	old.x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(-(c->player.speed_turn)) -
		c->player.plane.y * sin(-(c->player.speed_turn));
	c->player.plane.y = old.x * sin(-(c->player.speed_turn)) +
		c->player.plane.y * cos(-(c->player.speed_turn));
}

void	move_left(t_ctx *c)
{
	t_dxy	old;

	old.x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(c->player.speed_turn) -
		c->player.dir.y * sin(c->player.speed_turn);
	c->player.dir.y = old.x * sin(c->player.speed_turn) +
		c->player.dir.y * cos(c->player.speed_turn);
	old.x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(c->player.speed_turn) -
		c->player.plane.y * sin(c->player.speed_turn);
	c->player.plane.y = old.x * sin(c->player.speed_turn) +
		c->player.plane.y * cos(c->player.speed_turn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straffing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:22:05 by agaubert          #+#    #+#             */
/*   Updated: 2020/09/03 15:22:07 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_dxy	*rotate_90_right(t_ctx *c)
{
	t_dxy *new;

	if (!(new = ft_calloc(1, sizeof(*new))))
		exit_program(c, MEMORY_ERROR);
	new->x = (c->player.dir.x * 0) +
		(c->player.dir.y * 1);
	new->y = (c->player.dir.x * -1) +
		(c->player.dir.y * 0);
	return (new);
}

static t_dxy	*rotate_90_left(t_ctx *c)
{
	t_dxy *new;

	if (!(new = ft_calloc(1, sizeof(*new))))
		exit_program(c, MEMORY_ERROR);
	new->x = (c->player.dir.x * 0) +
		(c->player.dir.y * -1);
	new->y = (c->player.dir.x * 1) +
		(c->player.dir.y * 0);
	return (new);
}

void			strafe_right(t_ctx *c)
{
	int		new_x;
	int		new_y;
	t_dxy	*new_dir;

	new_dir = rotate_90_right(c);
	new_x = (int)(c->player.pos.x + new_dir->x * c->player.speed_move);
	new_y = (int)(c->player.pos.y + new_dir->y * c->player.speed_move);
	if (c->map[new_x][(int)c->player.pos.y] == '0')
		c->player.pos.x += new_dir->x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][new_y] == '0')
		c->player.pos.y += new_dir->y * c->player.speed_move;
	free(new_dir);
}

void			strafe_left(t_ctx *c)
{
	int		new_x;
	int		new_y;
	t_dxy	*new_dir;

	new_dir = rotate_90_left(c);
	new_x = (int)(c->player.pos.x + new_dir->x * c->player.speed_move);
	new_y = (int)(c->player.pos.y + new_dir->y * c->player.speed_move);
	if (c->map[new_x][(int)c->player.pos.y] == '0')
		c->player.pos.x += new_dir->x * c->player.speed_move;
	if (c->map[(int)c->player.pos.x][new_y] == '0')
		c->player.pos.y += new_dir->y * c->player.speed_move;
	free(new_dir);
}

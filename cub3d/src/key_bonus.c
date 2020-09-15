/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:52:58 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:54:04 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press(int key, t_ctx *c)
{
	if (key == KEY_UP)
		c->player.move_up = 1;
	if (key == KEY_DOWN)
		c->player.move_down = 1;
	if (key == KEY_RIGHT)
		c->player.move_right = 1;
	if (key == KEY_LEFT)
		c->player.move_left = 1;
	if (key == STRAFE_RIGHT)
		c->player.strafe_right = 1;
	if (key == STRAFE_LEFT)
		c->player.strafe_left = 1;
	if (key == KEY_ESC)
		exit_program(c, 0);
	return (0);
}

int	key_release(int key, t_ctx *c)
{
	if (key == KEY_UP)
		c->player.move_up = 0;
	if (key == KEY_DOWN)
		c->player.move_down = 0;
	if (key == KEY_RIGHT)
		c->player.move_right = 0;
	if (key == KEY_LEFT)
		c->player.move_left = 0;
	if (key == STRAFE_RIGHT)
		c->player.strafe_right = 0;
	if (key == STRAFE_LEFT)
		c->player.strafe_left = 0;
	return (0);
}

int	exit_hook(t_ctx *c)
{
	exit_program(c, 0);
	return (0);
}

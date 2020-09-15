/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:54:23 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:54:28 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop_hook(t_ctx *c)
{
	if (c->player.move_up)
		move_up(c);
	if (c->player.move_down)
		move_down(c);
	if (c->player.move_right)
		move_right(c);
	if (c->player.strafe_right)
		strafe_right(c);
	if (c->player.move_left)
		move_left(c);
	if (c->player.strafe_left)
		strafe_left(c);
	raycasting(c);
	if (c->do_screenshot == 1)
		save_screenshot(c);
	mlx_put_image_to_window(c->mlx_ptr, c->win_ptr, c->screen.img_ptr, 0, 0);
	mlx_do_sync(c->mlx_ptr);
	return (0);
}

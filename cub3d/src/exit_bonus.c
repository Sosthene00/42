/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:52:21 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:52:26 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd(WRONG_FILE, 2);
	else if (error_code == 2)
		ft_putstr_fd(ERROR_PARSING, 2);
	else if (error_code == 3)
		ft_putstr_fd(ERROR_WRITING, 2);
	else if (error_code == 9)
		ft_putstr_fd(MEMORY_ERROR, 2);
	else
		ft_putstr_fd("Unknown error\n", 2);
}

void	exit_program(t_ctx *c, int error_code)
{
	if (error_code != 0)
		print_error(error_code);
	if (c == NULL)
		exit(error_code);
	if (c->fd != 0)
	{
		if (close(c->fd) < 0)
			exit(1);
	}
	mlx_do_key_autorepeaton(c->mlx_ptr);
	if (c->win_ptr != NULL)
	{
		mlx_clear_window(c->mlx_ptr, c->win_ptr);
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
		free_all(c);
	}
	exit(error_code);
}

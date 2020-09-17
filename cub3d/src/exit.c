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

#include "cub3d.h"

static t_err	errors[] =
{
	{ WRONG_FILE, "File absent or wrong extension\n" },
	{ OPEN_FAILURE, "Can't open file\n" },
	{ INVALID_PARAM, "Invalid Parameters\n" },
	{ MISSING_TEXTURE, "Texture file doesn't exist\n" },
	{ MAP_ERROR, "Incorrect map file content\n" },
	{ OPEN_MAP, "The map is not closed by walls\n" },
	{ MULTI_SPAWN, "Player can't have more than one starting point\n" },
	{ ERROR_WRITING, "Couldn't save a screenshot\n" },
	{ MEMORY_ERROR, "memory error while initializing mlx or malloc\n" },
	{ DEFAULT_ERROR, "Unknown error\n" }
};

static char	*catch_err(t_errid raised)
{
	int		i;

	i = 0;
	while (errors[i].id != DEFAULT_ERROR)
	{
		if (errors[i].id == raised)
			return (errors[i].msg);
		i++;
	}
	return ((char *)strerror(errno));
}

void	print_error(t_errid error_code)
{
	char	*msg;

	msg = catch_err(error_code);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
}

void	exit_program(t_ctx *c, t_errid error_code)
{
	if (error_code != 0)
		print_error(error_code);
	if (c == NULL)
		exit(EXIT_FAILURE);
	if (c->fd != 0)
	{
		if (close(c->fd) < 0)
			exit(EXIT_FAILURE);
	}
	mlx_do_key_autorepeaton(c->mlx_ptr);
	if (c->win_ptr != NULL)
	{
		mlx_clear_window(c->mlx_ptr, c->win_ptr);
		mlx_destroy_window(c->mlx_ptr, c->win_ptr);
		free_all(c);
	}
	if (error_code != 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

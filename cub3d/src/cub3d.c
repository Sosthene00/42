/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:47:01 by agaubert          #+#    #+#             */
/*   Updated: 2020/02/27 19:23:54 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_ctx	*c;

	if (((argc < 2) || (argc > 3)) || (check_file_extension(argv[1])))
	{
		print_error(1);
		exit(1);
	}
	c = init_ctx(argv[1]);
	if (argc == 3)
	{
		if (!(ft_strncmp(argv[2], SCREENSHOT_OPT, ft_strlen(SCREENSHOT_OPT))))
			c->do_screenshot = 1;
		else
			ft_putstr_fd(WRONG_ARG, 2);
	}
	mlx_loop_hook(c->mlx_ptr, loop_hook, c);
	mlx_hook(c->win_ptr, KEY_PRESS, KEY_PRESS_MASK, &key_press, c);
	mlx_hook(c->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, &key_release, c);
	mlx_hook(c->win_ptr, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK, &exit_hook, c);
	mlx_loop(c->mlx_ptr);
}

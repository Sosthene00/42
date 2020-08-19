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

#include "./cube3d.h"

int	main(int argc, char **argv)
{
	ctx	*c;

	if (((argc < 2) || (argc > 3)) || (check_file_extension(argv[1]) == 1))
	{
		print_error(1);
		exit(1);
	}
	c = init_ctx(argv[1]);
	if (argv[2] &&
		(ft_strncmp(argv[2], SCREENSHOT_OPT, ft_strlen(SCREENSHOT_OPT))) == 0)
		c->screenshot = 1;
	mlx_loop_hook(c->mlx_ptr, loop_hook, c);
	mlx_hook(c->win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press, c);
	mlx_hook(c->win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release, c);
	mlx_loop(c->mlx_ptr);
}

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

# include "./cube3d.h"

int main(int argc, char **argv)
{
	ctx	*context;

	if ((argc < 2) || (argc > 3) || (open(argv[1], O_RDONLY) < 0))
	{
		print_error(1);
		exit(1);
	}
	context = init_ctx();
	if (!(context->mlx_ptr = mlx_init()))
		exit(1);
	parse_map_file(argv[1], context);
	//blue_screen(mlx_ptr, win_ptr, map_data);
	mlx_key_hook(context->win_ptr, blue_screen, context);
	mlx_loop(context->mlx_ptr);
}

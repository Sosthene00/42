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
	void	*mlx_ptr;
	void	*win_ptr;
	map		*map_data;

	if (!(map_data = (map *)malloc(sizeof(map))))
		return (EXIT_FAILURE);
	if ((argc != 2) || (parse_map_file(argv[1], map_data) != 0))
	{
		print_error(1);
		return (EXIT_FAILURE);
	}
	mlx_ptr = mlx_init();
	win_ptr = init_win(mlx_ptr, map_data);
	blue_screen(mlx_ptr, win_ptr, map_data);
	mlx_loop(mlx_ptr);
}

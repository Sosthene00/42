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
	void *mlx_ptr;
	void *win_ptr;
	int i;
	int j;
	map *map_data;
	(void)argc;

	i = -1;
	j = -1;
	if (!(map_data = (map *)malloc(sizeof(map))))
		return (EXIT_FAILURE);
	if (parse_map_file(argv[1], map_data) != 0)
	{
		print_error(parse_map_file(argv[1], map_data));
		return (EXIT_FAILURE);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, map_data->x, map_data->y, "Test");
	while (++i < map_data->x)
	{
		while (++j < map_data->y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 254);
		}
		j = -1;
	}
	mlx_loop(mlx_ptr);
}

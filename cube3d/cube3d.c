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

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int x;
	int y;
	int i;
	int j;

	x = 500;
	y = 240;
	i = -1;
	j = -1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x, y, "Test");
	while (++i < x)
	{
		while (++j < y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 254);
		}
		j = -1;
	}
	mlx_loop(mlx_ptr);
}

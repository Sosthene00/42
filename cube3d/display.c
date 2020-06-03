#include "./cube3d.h"

void *init_win(void *mlx_ptr, map *map_data)
{
    void *win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, map_data->x, map_data->y, map_data->name);
    return (win_ptr);
}

void blue_screen(void *mlx_ptr, void *win_ptr, map *map_data)
{
    int i;
    int j;

    i = -1;
    j = -1;
	while (++i < map_data->x)
	{
		while (++j < map_data->y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 254);
		}
		j = -1;
	}
}
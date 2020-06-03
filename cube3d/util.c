#include "./cube3d.h"

map *init_map_data()
{
    map *map_data;

    if (!(map_data = (map *)malloc(sizeof(map))))
		return (NULL);
    bzero(map_data, sizeof(*map_data));
    return (map_data);
}
int is_in_screen_size(void *mlx_ptr, int x, int y)
{
  int *max_x;
  int *max_y;

  mlx_get_screen_size(mlx_ptr, max_x, max_y);
  if ((x <= max_x) && (y <= max_y))
    return (1);
  else
    return (0);
}
#include "./cube3d.h"

map *init_map_data()
{
    map *map_data;

    if (!(map_data = (map *)malloc(sizeof(map))))
		return (NULL);
    bzero(map_data, sizeof(*map_data));
    return (map_data);
}
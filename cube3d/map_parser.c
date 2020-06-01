# include "./cube3d.h"

// parse the map file
int parse_map_file(char *map_file, map *map_data)
{
    int fd;

    if ((fd = open(map_file, O_RDONLY)) < 0)
        return (1);
    map_data->x = 0;
    map_data->y = 0;

    return (0);
}
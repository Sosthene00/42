# include "./cube3d.h"

int get_identifier(char *line, char *identifier)
{
    // return either 2 or -1
    ft_bzero(identifier, 4);
    if (!(ft_memccpy(identifier, line, ' ', 3)))
        return (-1);
    return (2);
}

int get_xy_value(char *line, map *map_data)
{
    int i;
    char tmp[5];

    while (*line && ((map_data->x == 0) || (map_data->y == 0)))
    {
        i = 0;
        while (*line == ' ')
            line++;
        while ((ft_isdigit(*line)) != 0)
        {
            tmp[i] = *line;
            i++;
            line++;
        }
        tmp[i] = '\0';
        if (map_data->x == 0)
            map_data->x = ft_atoi(tmp);
        else
            map_data->y = ft_atoi(tmp);
        
    }
    return (0);
}

int update_data(char *line, map *map_data)
{
    // Take a line, parse the identifier and dispatch the content to the right function 
    // to update map_data
    char *identifier;
    int i;

    if (!(identifier = ft_calloc(4, sizeof(*identifier))))
        return (2);
    if ((i = get_identifier(line, identifier) > 0))
        line = line + i;
    else
        return (2);
    
    if ((identifier[0] == 'R') && (identifier[1] == ' '))
    {
        // Parse x and y value from file, return 0 if ok, 2 otherwise
        if (get_xy_value(line, map_data) == 0)
            return (0);
        else
            return (2);
    }
    return (2);
}

// parse the map file
int parse_map_file(char *map_file, map *map_data)
{
    int fd;
    int ret;
    char *line;

    //if ((map_file == NULL) || (fd = open(map_file, O_RDONLY)) < 0)
    if ((fd = open(map_file, O_RDONLY)) < 0)
        return (1);
    map_data->name = map_file;
    while (get_next_line(fd, &line) > 0)
    {
        if (ft_isalpha(line[0]))
        {
            ret = update_data(line, map_data);
            if (ret == 2)
                break;
        }
        else
            continue;
    }
    return (ret);
}
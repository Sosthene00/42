# include "./cube3d.h"

char *get_identifier(char *line)
{
    char *identifier;

    if (!(identifier = malloc(sizeof(*identifier)*3)))
        return (NULL);
    ft_bzero(identifier, 3);
    ft_memccpy(identifier, line, 32, 2);
    return (identifier);
}

int update_data(char *line, map *map_data)
{
    char *identifier;
    char temp[BUFFER_SIZE + 1];
    int i;

    identifier = get_identifier(line);
    if ((identifier[0] == 'R') && (identifier[1] == ' '))
    {
        while (*++line)
        {
            i = 0;
            while (*line == 32)
                line++;
            while ((ft_isdigit(*line)) != 0)
            {
                temp[i] = *line;
                i++;
                line++;
            }
            temp[i] = '\0';
            map_data->x = ft_atoi(temp);
            i = 0;
            while (*line == 32)
                line++;
            while ((ft_isdigit(*line)) != 0)
            {
                temp[i] = *line;
                i++;
                line++;
            }
            map_data->y = ft_atoi(temp);
            return (0);
        }
    }
    return (2);
}

// parse the map file
int parse_map_file(char *map_file, map *map_data)
{
    int fd;
    int ret;
    char *line;

    if ((map_file == NULL) || (fd = open(map_file, O_RDONLY)) < 0)
        return (1);
    map_data->name = map_file;
    while (get_next_line(fd, &line) > 0)
    {
        if (ft_isalpha(line[0]))
            ret = update_data(line, map_data);
        else
            continue;
    }
    return (ret);
}
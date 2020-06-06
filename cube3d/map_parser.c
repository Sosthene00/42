# include "./cube3d.h"

int get_identifier(char *line, char *identifier)
{
    // return either 2 or -1
    ft_bzero(identifier, 4);
    if (!(ft_memccpy(identifier, line, ' ', 3)))
        return (-1);
    return (2);
}

int get_xy_value(char *line, ctx *context)
{
    int i;
    char tmp[5];

    while (*line && ((context->win_x == 0) || (context->win_y == 0)))
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
        if (context->win_x == 0)
            context->win_x = (unsigned int)ft_atoi(tmp);
        else
            context->win_y = (unsigned int)ft_atoi(tmp);
    }
    if (is_in_screen_size(context->mlx_ptr, context->win_x, context->win_y) == 1)
        return (0);
    else
        return (2);
}

int update_data(char *line, ctx *context)
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
        if (get_xy_value(line, context) == 0)
        {
            init_mlx(context);
            return (0);
        }
        else
            return (2);
    }
    return (2);
}

// parse the map file
int parse_map_file(char *map_file, ctx *context)
{
    int fd;
    int ret;
    char *line;

    //if ((map_file == NULL) || (fd = open(map_file, O_RDONLY)) < 0)
    if ((fd = open(map_file, O_RDONLY)) < 0)
        exit(1);
    context->name = map_file;
    while (get_next_line(fd, &line) > 0)
    {
        if (ft_isalpha(line[0]))
        {
            ret = update_data(line, context);
            if (ret == 2)
                break;
        }
        else
            continue;
    }
    return (ret);
}
# include "./cube3d.h"

unsigned int    convert_color(int r, int g, int b)
{
    unsigned int color;

    if ((r < 0) || (r > 255) ||\
        (g < 0) || (g > 255) ||\
        (b < 0) || (b > 255))
        return (pow(2, 32) - 1);
    color = (r << 16) + (g << 8) + b;
    return (color);
}

int get_xy_value(char *line, ctx *context)
{
    char **val;

    val = ft_split(line, ' ');
    if (!(val[0]) || !(val[1]) || !(ft_isdigit(*val[0])) || !(ft_isdigit(*val[1])))
        return (2);
    context->win_x = ft_atoi(val[0]);
    context->win_y = ft_atoi(val[1]);
    if (is_in_screen_size(context->mlx_ptr, context->win_x, context->win_y) == 1)
        return (0);
    else
        return (2);
}

int get_color(char *line, ctx *context)
{
    char **val;
    char identifier;
    unsigned int color;

    identifier = *line;
    while (!(ft_isdigit(*line)))
        line++;
    val = ft_split(line, ',');
    if (!(val[0]) || !(val[1]) || !(val[2]) || \
        !(ft_isdigit(*val[0])) || !(ft_isdigit(*val[1])) || !(ft_isdigit(*val[2])))
        return (2);
    color = convert_color(ft_atoi(val[0]), ft_atoi(val[1]), ft_atoi(val[2]));
    if (color == (pow(2, 32) - 1))
        return (2);
    if (identifier == 'C')
        context->color.color_sky = color;
    else if (identifier == 'F')
        context->color.color_floor = color;
    return (0);
}

int update_data(char *line, ctx *context)
{
    // Take a line, parse the identifier and dispatch the content to the right function 
    if (ft_strncmp(line, RESOLUTION, 2) == 0)
    {
        // Parse x and y value from file, return 0 if ok, 2 otherwise
        if (get_xy_value((line+2), context) == 0)
        {
            init_win(context);
            return (0);
        }
    }
    else if ((ft_strncmp(line, CEILING, 2) == 0) || (ft_strncmp(line, FLOOR, 2) == 0))
    {
        if (get_color((line), context) == 0)
            return (0);
    }
    return (2);
}

// parse the map file
int parse_map_file(char *map_file, ctx *context)
{
    int fd;
    int ret;
    char *line;

    if ((fd = open(map_file, O_RDONLY)) < 0)
        exit(1);
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
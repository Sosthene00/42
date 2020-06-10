# include "./cube3d.h"

unsigned int    convert_color(int r, int g, int b)
{
    unsigned int color;

    if ((r < 0) || (r > 255) ||\
        (g < 0) || (g > 255) ||\
        (b < 0) || (b > 255))
        return (INT_MAX);
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
    adapt_screen_size(context);
    return (0);
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
    if (color == INT_MAX)
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

//get a texture for the walls, or sprite

// parse the map itself
char **get_map(char *buf)
{
    char **map;
    char *trimmed;

    trimmed = ft_strtrim(buf, "+");
    map = ft_split(trimmed, '+');
    return (map);
}

// parse the map file
int parse_file(char *map_file, ctx *context)
{
    int fd;
    char *line;
    char *buf;
    char *sep;

    if ((fd = open(map_file, O_RDONLY)) < 0)
        exit(1);
    if (!(buf = malloc(sizeof(*buf))) || !(sep = ft_strjoin("", "+")))
        return (9);
    ft_bzero(buf, 1);
    while (get_next_line(fd, &line) > 0)
    {
        if (context->complete < 3 && ft_isalpha(line[0]))
        {
            if (update_data(line, context) == 2)
                break;
            context->complete++;
        }
        else if (context->complete == 3)
        {
            buf = ft_strjoin(buf, line);
            buf = ft_strjoin(buf, sep);
        }
    }
    context->map = get_map(buf);
    return (0);
}
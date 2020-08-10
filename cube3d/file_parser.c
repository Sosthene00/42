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

int get_xy_value(char **val, ctx *c)
{
    if (!(val[0]) || !(val[1]) || !(ft_isdigit(*val[0])) || !(ft_isdigit(*val[1])))
        return (2);
    //TODO: write those values in c->screen.width and heigth, and modify the rest of the code
    // accordingly
    c->screen.width = ft_atoi(val[0]);
    c->screen.height = ft_atoi(val[1]);
    adapt_screen_size(c);
    return (0);
}

int get_color(char **items, ctx *c)
{
    char **val;
    unsigned int color;

    val = ft_split(items[1], ',');
    if (!(val[0]) || !(val[1]) || !(val[2]) || \
        !(ft_isdigit(*val[0])) || !(ft_isdigit(*val[1])) || !(ft_isdigit(*val[2])))
        return (2);
    color = convert_color(ft_atoi(val[0]), ft_atoi(val[1]), ft_atoi(val[2]));
    if (color == INT_MAX)
        return (2);
    if (items[0][0] == 'C')
        c->color.sky = color;
    else if (items[0][0] == 'F')
        c->color.floor = color;
    return (0);
}

int update_data(char **items, ctx *c)
{
    // Take a line, parse the identifier and dispatch the content to the right function 
    if ((items[0][0] == RESOLUTION) && (items[0][1] == 0))
    {
        // Parse x and y value from file, return 0 if ok, 2 otherwise
        if (get_xy_value((items+1), c) == 0)
        {
            init_win(c);
            return (0);
        }
    }
    else if (((items[0][0] == CEILING) || (items[0][0] == FLOOR)) && (items[0][1] == 0))
    {
        if (get_color(items, c) == 0)
            return (0);
    }
    else if (((items[0][0] == SPRITE) && (items[0][1] == 0)) || 
        (ft_strnstr(WALLS, items[0], ft_strlen(WALLS))))
    {
        if (extract_textures(items, c) == 0)
            return (0);
    }
    return (2);
}

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
int parse_file(char *map_file, ctx *c)
{
    char *line;
    char **items;
    char *buf;
    char *sep;

    if ((c->fd = open(map_file, O_RDONLY)) < 0)
        exit(1);
    if (!(buf = malloc(sizeof(*buf))) || !(sep = ft_strjoin("", "+")))
        return (9);
    ft_bzero(buf, 1);
    while (get_next_line(c->fd, &line) > 0)
    {
        if (c->complete < EXPECTED_ARG && ft_isalpha(line[0]))
        {
            items = ft_split(line, ' ');
            if (update_data(items, c) == 2)
                break;
            c->complete++;
        }
        else if (c->complete == EXPECTED_ARG && *line)
        {
            buf = ft_strjoin(buf, line);
            buf = ft_strjoin(buf, sep);
        }
        else if ((*line == '\0') && (*buf != '\0'))
            return (2);
    }
    if (close(c->fd) < 0)
        return (2);
    c->fd = 0;
    c->map = get_map(buf);
    if (read_map(c) == 2)
        return (2);
    return (0);
}
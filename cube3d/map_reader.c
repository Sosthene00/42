#include "cube3d.h"

static int sanity_check(char *line, int i, int map_width)
{
    while (*line && (*line == ' '))
        line++;
    if (*line != '1')
        return (2);
    while (*line)
    {
        if ((i == 0) || (map_width > 0))
        {
            if (!((*line == '1') || (*line == ' ')))
                return (2);
        }
        else
        {
            if (!(ft_strchr(PLAYER_START, *line) || \
                ft_strchr(MAP_CASE, *line)))
                return (2);
        }
        line++;
    }
    //TODO: must be able to have blank space inside the map, and not only at beginning/end
    //of the line
    if (*(line - 1) != '1')
        return (2);
    return (0);
}
// extract the necessary information
static void update_player(char dir, int x, int y, ctx *c)
{
    if ((c->player.pos.x + c->player.pos.y) > 0)
        exit_program(c, 2);
    c->player.pos.x = x;
    c->player.pos.y = y;
    if (dir == 'N')
    {
        c->player.dir.x = -1;
        c->player.plane.y = 0.66;
    }
    else if (dir == 'S')
    {
        c->player.dir.x = 1;
        c->player.plane.y = -0.66;
    } 
    else if (dir == 'W')
    {
        c->player.dir.y = -1;
        c->player.plane.x = -0.66;
    } 
    else if (dir == 'E')
    {
        c->player.dir.y = 1;
        c->player.plane.x = 0.66;
    }
    c->map[x][y] = '0'; 
}

int    read_map(ctx *c)
{
    int x;
    int y;

    x = y = 0;
    while (c->map[x])
    {
        if (sanity_check(c->map[x], x, c->map_width) == 2)
            return (2);
        while (c->map[x][y])
        {
            if (ft_strchr(PLAYER_START, c->map[x][y]))
                update_player(c->map[x][y], x, y, c);
            if (c->map[x][y] == '2')
                update_sprite(c, x, y);
            y++;
        }
        if (y > c->map_height)
            c->map_height = y;
        y = 0;
        x++;
    }
    c->map_width = x;
    if (sanity_check(c->map[x-1], x, c->map_width) == 2 || \
            c->player.pos.x == 0)
        return (2);
    return (0);
}
#include "cube3d.h"

/*static int sanity_check(char **map, ctx *c)
{

}*/

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
}

static int read_line(char *line, int x, ctx *c)
{
    int y;

    y = 0;
    while (line[y])
    {
        if (line[y] == ' ' || line[y] == '0' ||
            line[y] == '1')
            y++;
        else if (ft_strchr(PLAYER_START, line[y]))
        {
            update_player(line[y], x, y, c);
            c->map[x][y] = '0'; 
        }
        else if (line[y] == '2')
            update_sprite(c, x, y);
        else
            return (2);
    }
    return (0);
}


int    read_map(ctx *c)
{
    int x;

    x = 0;
    while (c->map[x])
    {
        if (read_line(c->map[x], x, c) == 2)
            exit_program(c, 2);
        x++;
    }
    c->map_width = x;
    /*if (sanity_check(c->map, c) == 2 || c->player.pos.x == 0)
        return (2);*/
    return (0);
}
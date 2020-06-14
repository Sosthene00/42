#include "cube3d.h"

// check for invalid map
int sanity_check(char *line, int i, int map_height)
{
    while (*line && (*line == ' '))
        line++;
    if (*line != '1')
        return (2);
    while (*line)
    {
        if ((i == 0) || (map_height > 0))
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
    if (*(line - 1) != '1')
        return (2);
    return (0);
}
// extract the necessary information
void update_player(char dir, int i, int j, ctx *c)
{
    if ((c->player.pos.x + c->player.pos.y) > 0)
        exit_program(c, 2);
    c->player.pos.x = i;
    c->player.pos.y = j;
    if (dir == 'N')
    {
        c->player.dir.x = -1;
        c->player.dir.y = 0;
    }
    else if (dir == 'S')
    {
        c->player.dir.x = 1;
        c->player.dir.y = 0;
    } 
    else if (dir == 'W')
    {
        c->player.dir.x = 0;
        c->player.dir.y = -1;
    } 
    else if (dir == 'E')
    {
        c->player.dir.x = 0;
        c->player.dir.y = 1;
    }
    c->map[i][j] = '0'; 
}

int    read_map(ctx *c)
{
    int i;
    int j;

    i = j = 0;
    while (c->map[i])
    {
        if (sanity_check(c->map[i], i, c->map_height) == 2)
            return (2);
        while (c->map[i][j])
        {
            if (ft_strchr(PLAYER_START, c->map[i][j]))
                update_player(c->map[i][j], i, j, c);
            j++;
        }
        if (j > c->map_width)
            c->map_width = j;
        j = 0;
        i++;
    }
    c->map_height = i;
    if (sanity_check(c->map[i-1], i, c->map_height) == 2 || \
            c->player.pos.x == 0)
        return (2);
    return (0);
}
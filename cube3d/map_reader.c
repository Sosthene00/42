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
void update_player(char c, int i, int j, ctx *context)
{
    context->player.pos.x = j;
    context->player.pos.y = i;
    if (c == 'N')
    {
        context->player.dir.x = 0;
        context->player.dir.y = -1;
    }
    else if (c == 'S')
    {
        context->player.dir.x = 0;
        context->player.dir.y = 1;
    } 
    else if (c == 'W')
    {
        context->player.dir.x = -1;
        context->player.dir.y = 0;
    } 
    else if (c == 'E')
    {
        context->player.dir.x = 1;
        context->player.dir.y = 0;
    } 
}

int    read_map(ctx *context)
{
    int i;
    int j;

    i = j = 0;
    while (context->map[i])
    {
        if (sanity_check(context->map[i], i, context->map_height) == 2)
            return (2);
        while (context->map[i][j])
        {
            if (ft_strchr(PLAYER_START, context->map[i][j]))
                update_player(context->map[i][j], i, j, context);
            j++;
        }
        if (j > context->map_width)
            context->map_width = j;
        j = 0;
        i++;
    }
    context->map_height = i;
    if (sanity_check(context->map[i-1], i, context->map_height) == 2 || \
            context->player.pos.x == 0)
        return (2);
    return (0);
}
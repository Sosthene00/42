#include "cube3d.h"

// check for invalid map
int map_sanity(char **map)
{

}
// extract the necessary information
void update_player(char c, int i, int j, ctx *context)
{
    if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
    {
        context->player.pos.x = j;
        context->player.pos.y = i;
    }
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
        while (context->map[i][j])
        {
            if ((i == 0) && ((context->map[i][j] == 1 || (context->map[i][j] == ' '))))
                return (2);
            else if (!(ft_strchr(AUTHORIZED_MAP, context->map[i][j])))
                return (2);
            update_player(context->map[i][j], context);
            j++;
        }
        if (j > context->map_width)
            context->map_width = j;
        j = 0;
        i++;
    }
    context->map_height = i;
    return (0);
}
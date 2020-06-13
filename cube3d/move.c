#include "cube3d.h"

void    move_up(ctx *context)
{
    if (context->map[(int)(context->player.pos.x + context->player.dir.x * context->player.speed_move)]
            [(int)context->player.pos.y] == '0')
        context->player.pos.x += context->player.dir.x * context->player.speed_move;
    if (context->map[(int)context->player.pos.x][(int)(context->player.pos.y + context->player.dir.y * 
            context->player.speed_move)] == '0')
        context->player.pos.y += context->player.dir.y * context->player.speed_move;
}

void    move_down(ctx *context)
{
    if (context->map[(int)(context->player.pos.x - context->player.dir.x * context->player.speed_move)]
            [(int)context->player.pos.y] == '0')
        context->player.pos.x -= context->player.dir.x * context->player.speed_move;
    if (context->map[(int)context->player.pos.x][(int)(context->player.pos.y - context->player.dir.y * 
            context->player.speed_move)] == '0')
        context->player.pos.y -= context->player.dir.y * context->player.speed_move;
}

void    stop(ctx *context)
{
    print_whole_screen(0xffffff, context);
}
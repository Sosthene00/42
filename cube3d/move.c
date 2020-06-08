#include "cube3d.h"

void    move_up(ctx *context)
{
    print_whole_screen(pick_random(), context);
    //context->player.move_up = 0;
}

void    move_down(ctx *context)
{
    print_whole_screen(0x000001, context);
    //context->player.move_down = 0;
}
#include "cube3d.h"

void    move_up(ctx *context)
{
    print_whole_screen(context->color.color_floor, context);
}

void    move_down(ctx *context)
{
    print_whole_screen(context->color.color_sky, context);
}

void    stop(ctx *context)
{
    print_whole_screen(0xffffff, context);
}
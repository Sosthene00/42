#include "./cube3d.h"

void adapt_screen_size(ctx *context)
{
  int *max_x;
  int *max_y;

  if (context->mlx_ptr == NULL)
    exit(1);
  if ((!(max_x = malloc(sizeof(*max_x)))) || (!(max_y = malloc(sizeof(*max_y)))))
    exit(1);
  mlx_get_screen_size(context->mlx_ptr, max_x, max_y);
  if ((context->win_x >= *max_x) || (context->win_y >= *max_y))
  {
    context->win_x = *max_x;
    context->win_y = *max_y;
  }
}

static void init_ply(ctx *context)
{
    context->player.move_up = 0;
    context->player.move_down = 0;
}

void init_win(ctx *context)
{
	if (!(context->win_ptr = mlx_new_window(context->mlx_ptr, context->win_x, \
                                          context->win_y, "Cub3d - Knee deep in Hell")))
		exit_program(context, 9);
	context->bpp = 0;
	context->s_line = 0;
	context->img = mlx_new_image(context->mlx_ptr, context->win_x, context->win_y);
	context->pxl = mlx_get_data_addr(context->img, &(context->bpp), &(context->s_line),
			&(context->ed));
}

ctx *init_ctx(char *filename)
{
    ctx *context;

    if (!(context = (ctx *)malloc(sizeof(ctx))))
		  exit_program(context, 9);
    bzero(context, sizeof(*context));
    if (!(context->mlx_ptr = mlx_init()))
      exit_program(context, 9);
    if ((parse_file(filename, context)) == 2)
      exit_program(context, 2);
    init_ply(context);
    return (context);
}

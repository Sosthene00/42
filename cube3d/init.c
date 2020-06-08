#include "./cube3d.h"

int is_in_screen_size(void *mlx_ptr, int x, int y)
{
  int *max_x;
  int *max_y;

  if (mlx_ptr == NULL)
    exit(1);
  if ((!(max_x = malloc(sizeof(*max_x)))) || (!(max_y = malloc(sizeof(*max_y)))))
    exit(1);
  mlx_get_screen_size(mlx_ptr, max_x, max_y);
  if ((x <= *max_x) && (y <= *max_y))
    return (1);
  else
    return (0);
}

void init_mlx(ctx *context)
{
	if (!(context->win_ptr = mlx_new_window(context->mlx_ptr, context->win_x, \
                                          context->win_y, "Cub3d - level 1")))
		exit(1);
}

ctx *init_ctx(char *filename)
{
    ctx *context;

    if (!(context = (ctx *)malloc(sizeof(ctx))))
		  exit_program(context, 9);
    bzero(context, sizeof(*context));
    if (!(context->mlx_ptr = mlx_init()))
      exit_program(context, 9);
    if ((parse_map_file(filename, context)) == 2)
      exit_program(context, 2);
    return (context);
}

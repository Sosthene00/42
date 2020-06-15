#include "./cube3d.h"

void adapt_screen_size(ctx *c)
{
  int *max_x;
  int *max_y;

  if (c->mlx_ptr == NULL)
    exit(1);
  if ((!(max_x = malloc(sizeof(*max_x)))) || (!(max_y = malloc(sizeof(*max_y)))))
    exit(1);
  mlx_get_screen_size(c->mlx_ptr, max_x, max_y);
  if ((c->win_x >= *max_x) || (c->win_y >= *max_y))
  {
    c->win_x = *max_x;
    c->win_y = *max_y;
  }
}

static void init_ply(ctx *c)
{
    c->player.speed_move = 0.05;
    c->player.speed_turn = 0.01;
}

void init_win(ctx *c)
{
	if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->win_x, \
                                          c->win_y, "Cub3d - Knee deep in Hell")))
		exit_program(c, 9);
	c->screen.img_ptr = mlx_new_image(c->mlx_ptr, c->win_x, c->win_y);
	c->screen.data = mlx_get_data_addr(c->screen.img_ptr, &(c->screen.bits_per_pixel), &(c->screen.size_line),
			&(c->screen.endianness));
}

ctx *init_ctx(char *filename)
{
    ctx *c;
    int error_code;

    if (!(c = (ctx *)malloc(sizeof(ctx))))
		  exit_program(c, 9);
    bzero(c, sizeof(*c));
    if (!(c->mlx_ptr = mlx_init()))
      exit_program(c, 9);
    if ((error_code = parse_file(filename, c)) != 0)
      exit_program(c, error_code);
    init_ply(c);
    return (c);
}

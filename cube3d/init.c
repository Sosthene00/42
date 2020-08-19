#include "./cube3d.h"

void		adapt_screen_size(ctx *c)
{
	int *max_x;
	int *max_y;

	if (c->mlx_ptr == NULL)
		exit_program(c, 9);
	if ((!(max_x = malloc(sizeof(*max_x)))))
		exit_program(c, 9);
	if ((!(max_y = malloc(sizeof(*max_y)))))
		exit_program(c, 9);
	mlx_get_screen_size(c->mlx_ptr, max_x, max_y);
	if ((c->screen.width >= *max_x) || (c->screen.height >= *max_y))
	{
		c->screen.width = *max_x;
		c->screen.height = *max_y;
	}
	free(max_x);
	free(max_y);
}

static void	init_ply(ctx *c)
{
	c->player.speed_move = 0.05;
	c->player.speed_turn = 0.01;
}

int			init_win(ctx *c)
{
	if (!(c->win_ptr = mlx_new_window(c->mlx_ptr, c->screen.width, \
			c->screen.height, "Cub3d - Knee deep in Hell")))
		exit_program(c, 9);
	c->screen.img_ptr = mlx_new_image(c->mlx_ptr, c->screen.width,
		c->screen.height);
	c->screen.data = mlx_get_data_addr(c->screen.img_ptr,
		&(c->screen.bits_per_pixel), &(c->screen.size_line),
		&(c->screen.endianness));
	return (0);
}

ctx			*init_ctx(char *filename)
{
	ctx		*c;
	double	*zbuffer;
	int		error_code;

	if (!(c = (ctx *)ft_calloc(1, sizeof(*c))))
		exit_program(c, 9);
	if (!(c->mlx_ptr = mlx_init()))
		exit_program(c, 9);
	if ((error_code = parse_file(filename, c)) != 0)
		exit_program(c, error_code);
	init_ply(c);
	if (!(zbuffer = ft_calloc(c->screen.width, sizeof(*zbuffer))))
		exit_program(c, 9);
	c->ray.zbuffer = zbuffer;
	return (c);
}

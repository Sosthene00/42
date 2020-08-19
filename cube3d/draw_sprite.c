#include "cube3d.h"

void	get_values(ctx *c, sprt *s)
{
	s->transformX = s->invDet * (c->player.dir.y *
		s->spriteX - c->player.dir.x * s->spriteY);
	s->transformY = s->invDet * (-(c->player.plane.y) *
		s->spriteX + c->player.plane.x * s->spriteY);
	s->screenX = (int)((c->screen.width / 2) *
		(1 + s->transformX / s->transformY));
	s->vMoveScreen = (int)(vMove / s->transformY);
	s->height = abs((int)(c->screen.height / (s->transformY))) / vDiv;
	s->drawStartY = -(s->height) / 2 + c->screen.height / 2 + s->vMoveScreen;
	if (s->drawStartY < 0)
		s->drawStartY = 0;
	s->drawEndY = s->height / 2 + c->screen.height / 2 + s->vMoveScreen;
	if (s->drawEndY >= c->screen.height)
		s->drawEndY = c->screen.height - 1;
	s->width = abs((int)(c->screen.height / s->transformY)) / uDiv;
	s->drawStartX = -(s->width) / 2 + s->screenX;
	if (s->drawStartX < 0)
		s->drawStartX = 0;
	s->drawEndX = s->width / 2 + s->screenX;
	if (s->drawEndX >= c->screen.width)
		s->drawEndX = c->screen.width - 1;
}

void	draw_stripes(ctx *c, img *texture, sprt *s)
{
	int				stripe;
	int				y;
	int				d;
	unsigned int	color;

	stripe = s->drawStartX - 1;
	while (++stripe < s->drawEndX)
	{
		c->ray.tex_x = (int)(256 * (stripe - (-(s->width) / 2 + s->screenX)) *
			c->sprite.width / s->width) / 256;
		if (s->transformY > 0 && stripe > 0 && stripe < c->screen.width &&
			s->transformY < c->ray.zbuffer[stripe])
		{
			y = s->drawStartY;
			while (y < s->drawEndY)
			{
				d = (y - s->vMoveScreen) * 256 - c->screen.height * 128 +
					s->height * 128;
				c->ray.tex_y = ((d * c->sprite.height) / s->height) / 256;
				if ((color = extract_color(c, texture) & 0x00FFFFFF) != 0)
					put_pxl(&(c->screen), stripe, y, color);
				y++;
			}
		}
	}
}

sprt	*init_sprite(ctx *c, img *texture)
{
	sprt *sprite_data;

	if (!(sprite_data = ft_calloc(1, sizeof((*sprite_data)))))
		exit_program(c, 9);
	sprite_data->spriteX = texture->map_x - c->player.pos.x;
	sprite_data->spriteY = texture->map_y - c->player.pos.y;
	sprite_data->invDet = 1.0 / (c->player.plane.x * c->player.dir.y -
		c->player.dir.x * c->player.plane.y);
	return (sprite_data);
}

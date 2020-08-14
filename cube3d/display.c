#include "./cube3d.h"

void			put_pxl(img *img, int x, int y, unsigned int color)
{
	int		i;

	i = (x * 4) + (y * img->size_line);
	img->data[i] = color;
	img->data[++i] = color >> 8;
	img->data[++i] = color >> 16;
}

unsigned int extract_color(ctx *c, img *texture)
{
	unsigned int color;
	char	*buffer;
	int		i;

	i = (c->ray.tex_x * 4) + (c->ray.tex_y * texture->size_line);
	if ((buffer = malloc(sizeof(unsigned int))) == NULL)
		exit_program(c, 9);	
	ft_memcpy(buffer, (texture->data + i), sizeof(unsigned int));
	color = *(unsigned int*)(buffer);
	free(buffer);
	return (color);
}

int	draw_texture(ctx *c, img *texture, int x, int y, int drawEnd)
{
	double 			step;
	int				lineHeight;
	//int				d;
	unsigned int 	color;
	double			texPos;

	lineHeight = drawEnd - y;
	calc_tex_x(c, texture);
	step = (double)texture->height / lineHeight;
	texPos = (y - c->screen.height / 2 + lineHeight / 2) * step;
	while (y < drawEnd)
	{
		//d = y * 256 - c->screen.height * 128 + lineHeight * 128;
		//c->ray.tex_y = ((d * texture->height) / lineHeight) / 256;
		c->ray.tex_y = (int)texPos & (texture->height - 1);
		texPos += step;
		color = extract_color(c, texture);
		put_pxl(&(c->screen), x, y, color);
		y++;
	}
	return (y);
}

void	draw_sprite(ctx *c, img *sprite)
{
	img	*temp;
	int i;

	i = -1;
	while (++i < sprite->amt)
	{
		temp = sprite;
		while (temp->order != i)
			temp = temp->next;
		double spriteX;
		double spriteY;
		double invDet;
		spriteY = 0.0;
		spriteX = temp->map_x - c->player.pos.x;
		spriteY = temp->map_y - c->player.pos.y;
		invDet = 1.0 / (c->player.plane.x * c->player.dir.y - c->player.dir.x * c->player.plane.y);

		double transformX;
		double transformY;

		transformX = invDet * (c->player.dir.y * spriteX - c->player.dir.x * spriteY);
		transformY = invDet * (-(c->player.plane.y) * spriteX + c->player.plane.x * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])
		int spriteScreenX;
		spriteScreenX = (int)((c->screen.width / 2) * (1 + transformX / transformY));

		int vMoveScreen = (int)(vMove / transformY);

		int spriteHeight = abs((int)(c->screen.height / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
		int drawStartY = -spriteHeight / 2 + c->screen.height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + c->screen.height / 2 + vMoveScreen;
		if(drawEndY >= c->screen.height) drawEndY = c->screen.height - 1;

		//calculate width of the sprite
		int spriteWidth = abs( (int)(c->screen.height / (transformY))) / uDiv;
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= c->screen.width) drawEndX = c->screen.width - 1;

		//loop through every vertical stripe of the sprite on screen
		int stripe;
		unsigned int color;

		stripe = drawStartX;
		while(stripe < drawEndX)
		{
			c->ray.tex_x = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * c->sprite.width / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < c->screen.width && transformY < c->ray.zbuffer[stripe])
			{
				int y = drawStartY;
				while(y < drawEndY) //for every pixel of the current stripe
				{
					int d = (y-vMoveScreen) * 256 - c->screen.height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					c->ray.tex_y = ((d * c->sprite.height) / spriteHeight) / 256;
					color = extract_color(c, sprite);
					if((color & 0x00FFFFFF) != 0) 
						put_pxl(&(c->screen), stripe, y, color);
					y++;
				}
			}
			stripe++;
		}
    }
}

void    draw_line(ctx *c, img *texture, int x, int wall_top, int wall_bottom)
{
	int y;

	y = -1;
	while (++y < wall_top)
		put_pxl(&(c->screen), x, y, c->color.sky);
	y = draw_texture(c, texture, x, y, wall_bottom);
	while (++y < c->screen.height)
		put_pxl(&(c->screen), x, y, c->color.floor);
}

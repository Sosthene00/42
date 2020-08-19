#include "cube3d.h"

static void	swap_order(img *a, img *b)
{
	int c;

	c = a->order;
	a->order = b->order;
	b->order = c;
}

static img	*go_to_order(img *sprite, int n)
{
	img *temp;

	temp = sprite;
	while (temp->order != n)
		temp = temp->next;
	return (temp);
}

static void	bubblesort(img *sprite)
{
	int i;
	int j;
	img *a;
	img *b;

	i = -1;
	while (++i < (sprite->amt))
	{
		j = -1;
		while (++j < (sprite->amt) - i - 1)
		{
			a = go_to_order(sprite, j);
			b = go_to_order(sprite, j + 1);
			if (a->distance < b->distance)
				swap_order(a, b);
		}
	}
}

void		order_sprite_dist(ctx *c, img *sprite)
{
	img *temp;
	int count;

	count = 0;
	temp = sprite;
	while (temp)
	{
		temp->distance = (pow(c->player.pos.x - temp->map_x, 2) +
			pow(c->player.pos.y - temp->map_y, 2));
		temp->order = count;
		temp = temp->next;
		count++;
	}
	bubblesort(sprite);
}

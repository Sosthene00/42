#include "cube3d.h"

static void	add_sprite_to_list(img **alst, img *new)
{
	img	*temp;

	temp = *alst;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = new;
	new->order = temp->order + 1;
	temp = *alst;
	temp->amt = new->order + 1;
}

int			update_sprite(ctx *c, int x, int y)
{
	img *texture;
	img *root;

	c->map[x][y] = '0';
	root = &(c->sprite);
	if (root->map_x == 0)
	{
		root->map_x = ((double)x + 0.5);
		root->map_y = ((double)y + 0.5);
		return (0);
	}
	else
	{
		if (!(texture = ft_calloc(1, sizeof(*texture))))
			exit_program(c, 9);
		texture->map_x = ((double)x + 0.5);
		texture->map_y = ((double)y + 0.5);
		add_sprite_to_list(&root, texture);
	}
	return (0);
}

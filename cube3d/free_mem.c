#include "cube3d.h"

static void	free_sprite_list(img head)
{
	img *cur;
	img *next;

	cur = head.next;
	while (cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}

static void	free_context(ctx *c)
{
	if (c->ray.zbuffer)
		free(c->ray.zbuffer);
	if (c->sprite.next)
		free_sprite_list(c->sprite);
	if (c->map)
		ft_freesplit(c->map);
	if (c)
		free(c);
}

void		free_all(ctx *c)
{
	free_context(c);
}

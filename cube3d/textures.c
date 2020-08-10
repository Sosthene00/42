#include "cube3d.h"

void calc_tex_x(ctx *c, img *tex)
{
    if (c->ray.hit_side == 0)
        c->ray.wall_x = c->ray.pos.y + c->ray.dist * c->ray.dir.y;
    else
        c->ray.wall_x = c->ray.pos.x + c->ray.dist * c->ray.dir.x;
    c->ray.wall_x -= floor(c->ray.wall_x);
    c->ray.tex_x = (int)(c->ray.wall_x * (double)(tex->width));
    c->ray.tex_x = tex->width - c->ray.tex_x - 1;
}

int extract_textures(char **items, ctx *c)
{
    // Add a generic init_tex function that can initialize any wall or sprite
    if (ft_strncmp(items[0], "NO", 2) == 0)
    {
        if ((c->N_wall.img_ptr = mlx_xpm_file_to_image(c->mlx_ptr, items[1], &(c->N_wall.width), 
            &(c->N_wall.height))) == NULL)
            return (2);
        c->N_wall.data = mlx_get_data_addr(c->N_wall.img_ptr, &(c->N_wall.bits_per_pixel), 
            &(c->N_wall.size_line), &(c->N_wall.endianness));
    }
    else
    {
        if ((c->sprite.img_ptr = mlx_xpm_file_to_image(c->mlx_ptr, items[1], &(c->sprite.width), 
            &(c->sprite.height))) == NULL)
            return (2);
        c->sprite.data = mlx_get_data_addr(c->sprite.img_ptr, &(c->sprite.bits_per_pixel), 
            &(c->sprite.size_line), &(c->sprite.endianness));
    }
    return (0);
}
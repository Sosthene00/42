# include "cube3d.h"

void get_values(ctx *c, sprt *sprite)
{
    sprite->transformX = sprite->invDet * (c->player.dir.y * sprite->spriteX - 
        c->player.dir.x * sprite->spriteY);
    sprite->transformY = sprite->invDet * (-(c->player.plane.y) * sprite->spriteX + 
        c->player.plane.x * sprite->spriteY);
    sprite->screenX = (int)((c->screen.width / 2) * (1 + sprite->transformX / sprite->transformY));
    sprite->vMoveScreen = (int)(vMove / sprite->transformY);
    sprite->height = abs((int)(c->screen.height / (sprite->transformY))) / vDiv;
    sprite->drawStartY = -(sprite->height) / 2 + c->screen.height / 2 + sprite->vMoveScreen;
    if(sprite->drawStartY < 0) 
        sprite->drawStartY = 0;
    sprite->drawEndY = sprite->height / 2 + c->screen.height / 2 + sprite->vMoveScreen;
    if(sprite->drawEndY >= c->screen.height) 
        sprite->drawEndY = c->screen.height - 1;
    sprite->width = abs((int)(c->screen.height / sprite->transformY)) / uDiv;
    sprite->drawStartX = -(sprite->width) / 2 + sprite->screenX;
    if(sprite->drawStartX < 0) 
        sprite->drawStartX = 0;
    sprite->drawEndX = sprite->width / 2 + sprite->screenX;
    if(sprite->drawEndX >= c->screen.width) 
        sprite->drawEndX = c->screen.width - 1;
}

void   draw_stripes(ctx *c, img *texture, sprt *sprite)
{
    int stripe;
    int y;
    int d;
    unsigned int color;

    stripe = sprite->drawStartX;
    while(stripe < sprite->drawEndX)
    {
        c->ray.tex_x = (int)(256 * (stripe - (-(sprite->width) / 2 + sprite->screenX)) * c->sprite.width / sprite->width) / 256;
        if (sprite->transformY > 0 && stripe > 0 && stripe < c->screen.width && sprite->transformY < c->ray.zbuffer[stripe])
        {
            y = sprite->drawStartY;
            while(y < sprite->drawEndY)
            {
                d = (y - sprite->vMoveScreen) * 256 - c->screen.height * 128 + sprite->height * 128;
                c->ray.tex_y = ((d * c->sprite.height) / sprite->height) / 256;
                color = extract_color(c, texture);
                if((color & 0x00FFFFFF) != 0) 
                    put_pxl(&(c->screen), stripe, y, color);
                y++;
            }
        }
        stripe++;
    }
}

sprt    *init_sprite(ctx *c, img *texture)
{
    sprt *sprite_data;

    if (!(sprite_data = ft_calloc(1, sizeof((*sprite_data)))))
        exit_program(c, 9);
    sprite_data->spriteX = texture->map_x - c->player.pos.x;
    sprite_data->spriteY = texture->map_y - c->player.pos.y;
    sprite_data->invDet = 1.0 / (c->player.plane.x * c->player.dir.y - c->player.dir.x * c->player.plane.y);
    return (sprite_data);
}
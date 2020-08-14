# include "cube3d.h"

static void add_sprite_to_list(img **alst, img *new)
{
	img	*temp;

    temp = *alst;
    while (temp && temp->next)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->order = temp->order + 1;	
    temp = *alst;
    temp->amt = new->order + 1;
}

static void swap_order(img *a, img *b)
{
    int c;

    c = a->order;
    a->order = b->order;
    b->order = c;
}

/*static double   partition(struct ordered *arr, int low, int high)
{
    double pivot;
    int i;
    int j;

    pivot = arr[high].distance;
    i = (low - 1);
    j = low;
    while (j <= high-1)
    {
        if (arr[j].distance < pivot)
        {
            i++;
            swap(&arr[i].distance, &arr[j]);
        }
        j++;
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

static void quickSort_sprite(struct ordered *arr, int low, int high)
{
    if (low < high)
    {
        int pi;
    
        pi = partition(arr, low, high);
        quickSort_sprite(arr, low, pi-1);
        quickSort_sprite(arr, pi+1, high);
    }
}

void    sort_sprite(ctx *c, int *list, img *sprite)
{
    img *temp;
    struct ordered {
        int order;
        double distance;
    } *ordered;
    int i;

    i = 0;
    temp = sprite;
    if (!(ordered = ft_calloc(1, sizeof(*ordered))))
        exit_program(c, 9);
    while (temp && temp->next)
    {
        ordered[i].order = temp->order;
        ordered[i].distance = temp->distance;
        i++;
    }
    quickSort_sprite(ordered, 0, i);
}*/

static img *go_to_order(img *sprite, int n)
{
    img *temp;

    temp = sprite;
    while (temp->order != n)
        temp = temp->next;
    return (temp);
}

static void bubblesort(img *sprite)
{
    int i;
    int j;
    img *a;
    img *b;

    i = -1;
    while (++i < (sprite->amt))
    {
        j = -1;
        while (++j < (sprite->amt)-i-1)
        {
            a = go_to_order(sprite, j);
            b = go_to_order(sprite, j+1);
            if (a->distance < b->distance)
                swap_order(a, b);
        }
    }
}

void order_sprite_dist(ctx *c, img *sprite)
{
    img *temp;
    int count;

    count = 0;
    temp = sprite;
    while (temp)
    {
        temp->distance = ((c->player.pos.x - temp->map_x) * (c->player.pos.x - temp->map_x) + 
            (c->player.pos.y - temp->map_y) * (c->player.pos.y - temp->map_y));
        temp->order = count;
        temp = temp->next;
        count++;
    }
    bubblesort(sprite);
}

int update_sprite(ctx *c, int x, int y)
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
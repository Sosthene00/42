# include "cube3d.h"

int save_screenshot(ctx *c)
{
    int fd;
    bmp *file;

    c->screenshot = 0;
    if ((fd = open("screenshot", O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
        exit_program(c, 3);
    if (!(file = ft_calloc(1, sizeof(*file))))
        exit_program(c, 9);
    //get_bitmap_header(file, &(c->screen));
    /*if (write_to_disk(fd, file, c->screen) < 0)
        exit_program(c, 3);*/
    if (close(fd) < 0)
        exit_program(c, 3);
    free(file);
    return (0);
}
# include "./cube3d.h"

void    print_error(int error_code)
{
    if (error_code == 1)
        ft_putstr_fd(WRONG_FILE, 2);
    else if (error_code == 2)
        ft_putstr_fd(ERROR_PARSING, 2);
    else if (error_code == 9)
        ft_putstr_fd(MEMORY_ERROR, 2);
    else
        ft_putstr_fd("Unknown error\n", 2);
}

int check_file_extension(char *filename)
{
    char *extension;
    char **str;

    str = ft_split(filename, '.');
    extension = str[1];
    if (extension != NULL)
    {
        if (!(ft_strncmp(extension, FILE_EXT, 3)))
            return (0);
    }
    return (1);
}

void     exit_program(ctx *c, int error_code)
{
    if (error_code != 0)
        print_error(error_code);
    if (c == NULL)
        exit(error_code);
    if (c->fd != 0)
    {
        if (close(c->fd) < 0)
            exit(1);
    }
    mlx_do_key_autorepeaton(c->mlx_ptr);
    if (c->win_ptr != NULL)
    {
        mlx_clear_window(c->mlx_ptr, c->win_ptr);
        mlx_destroy_window(c->mlx_ptr, c->win_ptr);
        free(c);    
    }
    exit(error_code);
}

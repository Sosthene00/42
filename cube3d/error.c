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
        ft_putstr_fd("Unknown error code\n", 2);
}

void     exit_program(ctx *context, int error_code)
{
    if (error_code != 0)
        print_error(error_code);
    mlx_clear_window(context->mlx_ptr, context->win_ptr);
    mlx_destroy_window(context->mlx_ptr, context->win_ptr);    
    exit(1);
}

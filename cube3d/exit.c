# include "./cube3d.h"

void    print_error(int error_code)
{
    if (error_code == 1)
        ft_putstr_fd(WRONG_FILE, 2);
    else if (error_code == 2)
        ft_putstr_fd(ERROR_PARSING, 2);
    else
        ft_putstr_fd("Unknown error code\n", 2);
}

int     exit_program(void *mlx_ptr, void *win_ptr, int error_code)
{
    if (error_code != 0)
        print_error(error_code);
    mlx_clear_window(mlx_ptr, win_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);    
    return (error_code);
}

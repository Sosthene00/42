/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:37:05 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/03 16:32:32 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define EFILENONEX "The file doesn't exist"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	nb;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			nb = n * -1;
		}
		else
			nb = n;
		if (nb <= 9)
			ft_putchar_fd(nb + '0', fd);
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}

int	main(int ac, char **av)
{
	int	fd;
	int	ret;
	static char **line;

	ret = 1;
	if (ac == 1)
		fd = 0;
	else
	{
		fd = open(av[1], "O_RDONLY");
		if (fd < 0)
		{
			ft_putstr_fd(EFILENONEX, 2);
			return (1);
		}
	}
	while (ret != 0)
	{
		ret = get_next_line(fd, line);
		ft_putstr_fd(**line, 1);
		ft_putnbr_fd(ret, 1);
	}
	if (ret == -1)
		ft_putstr_fd("Something went wrong", 2);
	if (close(fd) < 0)
	{
		ft_putstr_fd("File didn't close properly", 2);
		return (1);
	}
	return (0);
}

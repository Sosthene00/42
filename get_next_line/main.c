/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:37:05 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/11 19:47:04 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int	ret;
	char *line;
	int i;

	ret = 1;
	i = 0;
	if (ac == 1)
		fd = 0;
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr_fd("ERROR: can't open file", 2);
			return (1);
		}
	}
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		i++;
		ft_putstr_fd("GNL output: ", 1);
		ft_putstr_fd(line, 1);
        ft_putstr_fd("\n", 1);
        free(line);
	}
	if (close(fd) < 0)
	{
		ft_putstr_fd("File didn't close properly", 2);
		return (1);
	}
	return (0);
}

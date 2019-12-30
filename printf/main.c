/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:32:50 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/30 20:01:57 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(int ac, char **av)
{
	char *var[ac];
	int i = 1;
	int	res;
	int	res2;

	if (ac == 1)
		return (1);
	while (i < ac)
	{
		var[i] = av[i];
		i++;
	}
	res = ft_printf("    %p    %x     %%\n", var[1], ft_atoi(var[2]));
	res2 = printf("    %p    %.1u     %%\n", var[1], ft_atoi(var[2]));
	printf("my output : %d\ntheir output : %d\n", res, res2);
	return (0);
}

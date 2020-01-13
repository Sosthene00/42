/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:32:50 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 20:37:46 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

int	main(int ac, char **av)
{
	//char *var[ac];
	//int i = 1;
	(void)ac;
	(void)av;
	int	res;
	int	res2;

	/*if (ac == 1)
		return (1);
	while (i < ac)
	{
		var[i] = av[i];
		i++;
	}*/
	res = ft_printf("%c", 'c');
	printf("\n");
	res2 = printf("%c", 'c');
	printf("\n");
	printf("my output : %d\ntheir output : %d\n", res, res2);
	system("leaks a.out");
	return (0);
}

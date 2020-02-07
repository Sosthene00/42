/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulong_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:46:31 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:49:08 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_ldigit(unsigned long n)
{
	int		i;
	size_t	nb;

	i = 0;
	if (n == 0)
		return (i = 1);
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int				ft_putulong_fd(unsigned long n, int fd)
{
	int i;

	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putulong_fd(n / 10, fd);
		ft_putulong_fd(n % 10, fd);
	}
	return (i = count_ldigit(n));
}

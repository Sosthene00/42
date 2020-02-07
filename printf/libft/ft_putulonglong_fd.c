/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulonglong_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:16:42 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/30 20:08:41 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_lldigit(unsigned long long n)
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

int				ft_putulonglong_fd(unsigned long long n, int fd)
{
	int i;

	if (n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putulonglong_fd(n / 10, fd);
		ft_putulonglong_fd(n % 10, fd);
	}
	return (i = count_lldigit(n));
}

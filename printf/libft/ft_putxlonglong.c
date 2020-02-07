/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxlonglong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:04:41 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 15:12:36 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int			ft_putxlonglong_fd(unsigned long long n, int fd, int upper)
{
	int		i;
	char	*set_low;
	char	*set_up;

	set_low = "0123456789abcdef";
	set_up = "0123456789ABCDEF";
	if (n <= 15)
		if (upper == 1)
			ft_putchar_fd(set_up[n], fd);
		else
			ft_putchar_fd(set_low[n], fd);
	else
	{
		ft_putxlonglong_fd(n / 16, fd, upper);
		ft_putxlonglong_fd(n % 16, fd, upper);
	}
	return (i = count_digit(n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:01:21 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/30 17:11:21 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_lldigit(long long n)
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

int		count_lldigit_minus(long long n)
{
	int		i;
	size_t	nb;

	i = 0;
	if (n == 0)
		return (i = 1);
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

size_t	convert_llneg(long long n)
{
	size_t	nb;

	if (n >= 0)
		return (nb = n);
	if (n == LLONG_MIN)
	{
		nb = (n + 1) * -1;
		return (nb + 1);
	}
	else
		return (nb = n * -1);
}

int		count_uldigit(unsigned long n, long pos)
{
	int i;

	i = 0;
	if (n == 0)
		return (i = 1);
	while (n != 0)
	{
		n /= pos;
		i++;
	}
	return (i);
}

int		count_ulldigit(unsigned long long n, long long pos)
{
	int i;

	i = 0;
	if (n == 0)
		return (i = 1);
	while (n != 0)
	{
		n /= pos;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:46:45 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/16 16:54:31 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_params(t_param **ptr)
{
	if (ptr && *ptr)
	{
		(*ptr)->type = 0;
		(*ptr)->padding = 0;
		(*ptr)->zero = 0;
		(*ptr)->precision = 0;
		(*ptr)->width = 0;
		(*ptr)->len = 0;
		(*ptr)->sign = 0;
		(*ptr)->alt = 0;
		(*ptr)->len_modif = 0;
		free(*ptr);
		*ptr = NULL;
	}
}

int		count_digit(int n)
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

int		count_ldigit(long n)
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

int		count_ldigit_minus(long n)
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

size_t	convert_lneg(long n)
{
	size_t	nb;

	if (n >= 0)
		return (nb = n);
	if (n == LONG_MIN)
	{
		nb = (n + 1) * -1;
		return (nb + 1);
	}
	else
		return (nb = n * -1);
}

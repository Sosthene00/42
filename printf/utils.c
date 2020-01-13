/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:32:18 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 19:48:41 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		count_digit_minus(int n)
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

int		count_udigit(size_t n, int pos)
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

int		extract_num(char *str)
{
	int		i;
	char	*num;

	i = 0;
	while (ft_isdigit((int)str[i++]))
		;
	if (!(num = malloc(sizeof(*num) * (i))))
		return (-1);
	i = -1;
	while (ft_isdigit((int)str[++i]))
		num[i] = str[i];
	num[i] = 0;
	i = ft_atoi(num);
	free(num);
	return (i);
}

int		count_width(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit((int)str[i++]))
		;
	return (i);
}

size_t	convert_neg(int n)
{
	size_t	nb;

	if (n >= 0)
		return (nb = n);
	if (n == INT_MIN)
	{
		nb = (n + 1) * -1;
		return (nb + 1);
	}
	else
		return (nb = n * -1);
}

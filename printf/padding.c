/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:50:51 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 19:52:13 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*fill_zero(int x, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_digit_minus(x);
	else if (params->zero == 1)
		len = params->width - count_digit(x) - params->sign;
	else
		return (res = NULL);
	if (len > 0)
	{
		if (!(res = malloc(sizeof(*res) * (len + 1))))
			return (NULL);
		res[len--] = 0;
		while (len >= 0)
			res[len--] = '0';
	}
	else
		res = NULL;
	return (res);
}

char	*fill_uzero(size_t x, int pos, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_udigit(x, pos);
	else if (params->zero == 1)
		len = params->width - count_udigit(x, pos) - params->sign;
	else
		return (res = NULL);
	if (len > 0)
	{
		if (!(res = malloc(sizeof(*res) * (len + 1))))
			return (NULL);
		res[len--] = 0;
		while (len >= 0)
			res[len--] = '0';
	}
	else
		res = NULL;
	return (res);
}

int		fill_spaces(int len)
{
	int		i;

	i = -1;
	while (++i < len)
		ft_putchar_fd(' ', 1);
	return (i);
}

char	*create_padding(int len, int zero)
{
	char	*padding;
	char	c;
	int		i;

	i = 0;
	if (zero == 1)
		c = '0';
	else
		c = ' ';
	if (!(padding = malloc(sizeof(*padding) * (len + 1))))
		return (NULL);
	while (i < len)
		padding[i++] = c;
	padding[i] = 0;
	return (padding);
}

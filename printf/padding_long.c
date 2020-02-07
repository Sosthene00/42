/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:13:27 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/30 20:46:58 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*lfill_zero(long x, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_ldigit_minus(x);
	else if (params->zero == 1)
		len = params->width - count_ldigit(x) - params->sign;
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

char	*lfill_uzero(unsigned long x, int pos, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_uldigit(x, pos);
	else if (params->zero == 1)
	{
		len = params->width - count_uldigit(x, pos) - params->sign;
		if (params->alt == 1 && x != 0)
			len -= 2;
	}
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

char	*llfill_zero(long long x, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_lldigit_minus(x);
	else if (params->zero == 1)
		len = params->width - count_lldigit(x) - params->sign;
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

char	*llfill_uzero(unsigned long long x, int pos, t_param *params)
{
	char	*res;
	int		len;

	if (params->precision > 0)
		len = params->precision - count_ulldigit(x, pos);
	else if (params->zero == 1)
	{
		len = params->width - count_ulldigit(x, pos) - params->sign;
		if (params->alt == 1 && x != 0)
			len -= 2;
	}
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

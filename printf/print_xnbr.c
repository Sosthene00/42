/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:14:28 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:46:03 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_xnbr(unsigned long long x, char *zero_prec, t_param *params)
{
	int i;

	i = 0;
	if (params->alt == 1 && x != 0)
		i += ft_putstr_fd((params->type == 'x') ? "0x" : "0X", 1);
	i += ft_putstr_fd(zero_prec, 1);
	i += ft_putxlong_fd(x, 1, (params->type == 'x') ? 0 : 1);
	return (i);
}

int			print_xint(int spaces, char *zero_prec, \
t_param *params, unsigned int x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
	}
	if (params->padding == 1)
	{
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
		i += fill_spaces(spaces);
	}
	return (i);
}

int			print_xlong(int spaces, char *zero_prec, \
t_param *params, unsigned long x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
	}
	if (params->padding == 1)
	{
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
		i += fill_spaces(spaces);
	}
	return (i);
}

int			print_xlonglong(int spaces, char *zero_prec, \
t_param *params, unsigned long long x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
	}
	if (params->padding == 1)
	{
		if (params->precision == 0 && x == 0)
			;
		else
			i += print_xnbr(x, zero_prec, params);
		i += fill_spaces(spaces);
	}
	return (i);
}

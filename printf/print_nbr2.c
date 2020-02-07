/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:12:52 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:44:47 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_longlong(int spaces, char *zero_prec, t_param *params, long long x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulonglong_fd(convert_llneg(x), 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulonglong_fd(convert_llneg(x), 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

int	print_ulong(int spaces, char *zero_prec, t_param *params, unsigned long x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulong_fd(x, 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulong_fd(x, 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

int	print_ulonglong(int spaces, char *zero_prec, \
t_param *params, unsigned long long x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulonglong_fd(x, 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulonglong_fd(x, 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:05:33 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:43:43 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_sign(long long x, int sign)
{
	if (x < 0)
	{
		ft_putchar_fd('-', 1);
		return (1);
	}
	else if (sign == 1)
	{
		ft_putchar_fd('+', 1);
		return (1);
	}
	else
		return (0);
}

int	print_int(int spaces, char *zero_prec, t_param *params, int x)
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
			i += ft_putunbr_fd(convert_neg(x), 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putunbr_fd(convert_neg(x), 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

int	print_long(int spaces, char *zero_prec, t_param *params, long x)
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
			i += ft_putulong_fd(convert_lneg(x), 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putulong_fd(convert_lneg(x), 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

int	print_uint(int spaces, char *zero_prec, t_param *params, unsigned int x)
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
			i += ft_putunbr_fd(x, 1);
	}
	if (params->padding == 1)
	{
		i += print_sign(x, params->sign);
		i += ft_putstr_fd(zero_prec, 1);
		if (params->precision == 0 && x == 0)
			;
		else
			i += ft_putunbr_fd(x, 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

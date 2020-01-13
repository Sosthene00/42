/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:05:33 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 20:41:21 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_int(int spaces, char *zero_prec, t_param *params, int x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		if (x < 0)
			i += ft_putstr_fd("-", 1);
		else if (params->sign == 1)
			i += ft_putstr_fd("+", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putunbr_fd(convert_neg(x), 1);
	}
	if (params->padding == 1)
	{
		if (x < 0)
			i += ft_putstr_fd("-", 1);
		else if (params->sign == 1)
			i += ft_putstr_fd("+", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putunbr_fd(convert_neg(x), 1);
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
		if (params->sign == 1)
			i += ft_putstr_fd("+", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putunbr_fd(x, 1);
	}
	if (params->padding == 1)
	{
		if (params->sign == 1)
			i += ft_putstr_fd("+", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putunbr_fd(x, 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

int	print_xint(int spaces, char *zero_prec, t_param *params, unsigned int x)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += fill_spaces(spaces);
		if (params->alt == 1)
			i += ft_putstr_fd((params->type == 'x') ? "0x" : "0X", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putxnbr_fd(x, 1, (params->type == 'x') ? 0 : 1);
	}
	if (params->padding == 1)
	{
		if (params->alt == 1)
			i += ft_putstr_fd((params->type == 'x') ? "0x" : "0X", 1);
		i += ft_putstr_fd(zero_prec, 1);
		i += ft_putxnbr_fd(x, 1, (params->type == 'x') ? 0 : 1);
		i += fill_spaces(spaces);
	}
	return (i);
}

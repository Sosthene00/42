/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:57:05 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 20:24:09 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format_int(int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	if (params->precision == 0 && x == 0)
		return (0);
	zero_prec = fill_zero(x, params);
	spaces = params->width - ft_strlen(zero_prec) - count_digit(x);
	params->sign == 1 && x >= 0 ? spaces-- : spaces;
	i += print_int(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int	format_uint(unsigned int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	if (params->precision == 0 && x == 0)
		return (0);
	zero_prec = fill_uzero(x, 10, params);
	spaces = params->width - ft_strlen(zero_prec) - count_udigit(x, 10);
	params->sign == 1 ? spaces-- : spaces;
	i += print_uint(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int	format_xint(unsigned int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	if (params->precision == 0 && x == 0)
		return (0);
	zero_prec = fill_uzero(x, 16, params);
	spaces = params->width - ft_strlen(zero_prec) - count_udigit(x, 16);
	params->sign == 1 ? spaces-- : spaces;
	i += print_xint(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

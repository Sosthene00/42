/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:07:49 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:48:22 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_spaces(long x, unsigned long u, \
char *zero_prec, t_param *params)
{
	int	spaces;

	spaces = 0;
	if (params->type == 'd')
	{
		spaces = params->width - ft_strlen(zero_prec) - count_ldigit(x);
		params->sign == 1 && x >= 0 ? spaces-- : spaces;
		(params->precision == 0 && x == 0) ? spaces++ : spaces;
	}
	else
	{
		if (params->type == 'x' || params->type == 'X')
		{
			spaces = params->width - ft_strlen(zero_prec) - \
			count_uldigit(u, 16);
			if (params->alt == 1 && u != 0)
				spaces -= 2;
		}
		else if (params->type == 'u')
			spaces = params->width - ft_strlen(zero_prec) - \
			count_uldigit(u, 10);
		params->sign == 1 ? spaces-- : spaces;
		(params->precision == 0 && u == 0) ? spaces++ : spaces;
	}
	return (spaces);
}

int			format_long(long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = lfill_zero(x, params);
	spaces = count_spaces(x, 0, zero_prec, params);
	i += print_long(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_ulong(unsigned long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = lfill_uzero(x, 10, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_ulong(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_xlong(unsigned long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = lfill_uzero(x, 16, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_xlong(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_longlong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:57:41 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 15:42:39 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_spaces(long long x, unsigned long long u, \
char *zero_prec, t_param *params)
{
	int	spaces;

	spaces = 0;
	if (params->type == 'd')
	{
		spaces = params->width - ft_strlen(zero_prec) - count_lldigit(x);
		params->sign == 1 && x >= 0 ? spaces-- : spaces;
		(params->precision == 0 && x == 0) ? spaces++ : spaces;
	}
	else
	{
		if (params->type == 'x' || params->type == 'X')
		{
			spaces = params->width - ft_strlen(zero_prec) \
			- count_ulldigit(u, 16);
			if (params->alt == 1 && u != 0)
				spaces -= 2;
		}
		else if (params->type == 'u')
			spaces = params->width - ft_strlen(zero_prec) \
			- count_ulldigit(u, 10);
		params->sign == 1 ? spaces-- : spaces;
		(params->precision == 0 && u == 0) ? spaces++ : spaces;
	}
	return (spaces);
}

int			format_longlong(long long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = llfill_zero(x, params);
	spaces = count_spaces(x, 0, zero_prec, params);
	i += print_longlong(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_ulonglong(unsigned long long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = llfill_uzero(x, 10, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_ulonglong(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_xlonglong(unsigned long long x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = llfill_uzero(x, 16, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_xlonglong(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

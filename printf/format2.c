/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:57:05 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 15:33:38 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_spaces(int x, unsigned int u, \
char *zero_prec, t_param *params)
{
	int	spaces;

	spaces = 0;
	if (params->type == 'd')
	{
		spaces = params->width - ft_strlen(zero_prec) - count_digit(x);
		params->sign == 1 && x >= 0 ? spaces-- : spaces;
		(params->precision == 0 && x == 0) ? spaces++ : spaces;
	}
	else
	{
		if (params->type == 'x' || params->type == 'X')
		{
			spaces = params->width - ft_strlen(zero_prec) - count_udigit(u, 16);
			if (params->alt == 1 && u != 0)
				spaces -= 2;
		}
		else if (params->type == 'u')
			spaces = params->width - ft_strlen(zero_prec) - count_udigit(u, 10);
		params->sign == 1 ? spaces-- : spaces;
		(params->precision == 0 && u == 0) ? spaces++ : spaces;
	}
	return (spaces);
}

int			format_int(int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = fill_zero(x, params);
	spaces = count_spaces(x, 0, zero_prec, params);
	i += print_int(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_uint(unsigned int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = fill_uzero(x, 10, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_uint(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

int			format_xint(unsigned int x, t_param *params)
{
	int		i;
	int		spaces;
	char	*zero_prec;

	i = 0;
	zero_prec = fill_uzero(x, 16, params);
	spaces = count_spaces(0, x, zero_prec, params);
	i += print_xint(spaces, zero_prec, params, x);
	free(zero_prec);
	return (i);
}

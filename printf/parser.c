/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:29:57 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/30 21:10:26 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	int_length(va_list ap, t_param *params)
{
	int i;

	i = 0;
	if (params->len_modif == 3)
		i += format_long(va_arg(ap, long), params);
	else if (params->len_modif == 4)
		i += format_longlong(va_arg(ap, long long), params);
	else
		i += format_int(va_arg(ap, int), params);
	return (i);
}

static int	uint_length(va_list ap, t_param *params)
{
	int i;

	i = 0;
	if (params->len_modif == 3)
		i += format_ulong(va_arg(ap, unsigned long), params);
	else if (params->len_modif == 4)
		i += format_ulonglong(va_arg(ap, unsigned long long), params);
	else
		i += format_uint(va_arg(ap, unsigned int), params);
	return (i);
}

static int	xint_length(va_list ap, t_param *params)
{
	int i;

	i = 0;
	if (params->len_modif == 3)
		i += format_xlong(va_arg(ap, unsigned long), params);
	else if (params->len_modif == 4)
		i += format_xlonglong(va_arg(ap, unsigned long long), params);
	else
		i += format_xint(va_arg(ap, unsigned int), params);
	return (i);
}

static int	conversion(va_list ap, t_param *params, int printed)
{
	int i;

	i = 0;
	if (params->type == 's')
		i += format_string(va_arg(ap, char *), params);
	else if (params->type == '%')
		i += format_char('%', params);
	else if (params->type == 'd')
		i += int_length(ap, params);
	else if (params->type == 'u')
		i += uint_length(ap, params);
	else if (params->type == 'x' || params->type == 'X')
		i += xint_length(ap, params);
	else if (params->type == 'p')
		i += format_ptr(va_arg(ap, void *), params);
	else if (params->type == 'c')
		i += format_char(va_arg(ap, int), params);
	else if (params->type == 'n')
		*(va_arg(ap, int *)) = printed;
	return (i);
}

int			parser(char *fmt, va_list ap)
{
	t_param	*params;
	int		i;

	i = 0;
	while (*fmt)
	{
		if (*(fmt) == '%')
		{
			if ((params = ft_newparam(++fmt, ap))->is_valid == 0)
			{
				free_params(&params);
				return (-1);
			}
			i += conversion(ap, params, i);
			fmt += params->len;
			free_params(&params);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			i++;
			fmt++;
		}
	}
	return (i);
}

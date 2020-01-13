/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:29:57 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 19:50:17 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	conversion(va_list ap, t_param *params, int printed)
{
	int i;

	i = 0;
	if (params->type == 's')
		i += format_string(va_arg(ap, char *), params);
	else if (params->type == '%')
		i += format_char('%', params);
	else if (params->type == 'd' || params->type == 'i')
		i += format_int(va_arg(ap, int), params);
	else if (params->type == 'u')
		i += format_uint(va_arg(ap, unsigned int), params);
	else if (params->type == 'x' || params->type == 'X')
		i += format_xint(va_arg(ap, unsigned int), params);
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
	return ((int)i);
}

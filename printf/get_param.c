/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:43:11 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/16 15:27:50 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		sanity_check(t_param *node)
{
	node->type = handle_type(node->type);
	if (node->width < 0)
	{
		node->width *= -1;
		node->padding = 1;
	}
	if (node->precision >= 0)
		node->zero = 0;
	if (node->padding == 1)
		node->zero = 0;
	if ((node->type == 'c' || node->type == 'p') && node->zero == 1)
		return (0);
	if ((node->type == 'c' || node->type == 'p') && node->precision > 0)
		return (0);
	return (1);
}

static int		handle_width(t_param *node, char *str, va_list ap)
{
	if (*str == '.')
	{
		if (str[1] == '*')
		{
			node->precision = va_arg(ap, int);
			return (2);
		}
		else
		{
			node->precision = extract_num(++str);
			return (count_width(str) + 1);
		}
	}
	else if (*str == '*')
	{
		node->width = va_arg(ap, int);
		return (1);
	}
	else
	{
		node->width = extract_num(str);
		return (count_digit(node->width));
	}
}

static int		handle_flags(t_param *node, char *str, va_list ap)
{
	char c;

	c = *str;
	if (c == '0')
		node->zero = 1;
	if (c == '-')
		node->padding = 1;
	if (c == '+')
		node->sign = 1;
	if (c == '#')
		node->alt = 1;
	if (c == 'h')
		return (h_modifier(node, str));
	if (c == 'l')
		return (l_modifier(node, str));
	if (c == '.' || c == '*')
		return (handle_width(node, str, ap));
	return (1);
}

static int		get_param(t_param *node, char *str, va_list ap)
{
	int	i;
	int	j;

	i = node->len - 1;
	j = 0;
	if (node->type == 'n')
		return (0);
	while (*str && i > 0)
	{
		if ((ft_strchr(FLAGS, *str) != 0))
			j = handle_flags(node, str, ap);
		else if (ft_isdigit(*str) == 1)
			j = handle_width(node, str, ap);
		else
			return (-1);
		str += j;
		i -= j;
	}
	return (0);
}

t_param			*ft_newparam(char *params, va_list ap)
{
	t_param	*node;
	int		i;

	i = 0;
	if (!(node = ft_calloc(1, sizeof(*node))))
		return (NULL);
	while (params[i] && \
	((node->type = ft_strchr(CONVERSION, params[i++])) == 0))
		;
	node->precision = -1;
	node->len = i;
	if (get_param(node, params, ap) == -1)
		return (node);
	params += node->len;
	node->is_valid = sanity_check(node);
	return (node);
}

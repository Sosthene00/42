/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:39:36 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/13 20:39:32 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*null_str(void)
{
	char *res;

	if (!(res = malloc(sizeof(*res) * (ft_strlen("(null)") + 1))))
		return (NULL);
	ft_strlcpy(res, "(null)", 7);
	free(res);
	return (res);
}

static int	print_str(char *to_print, char *padding, t_param *params)
{
	int i;

	i = 0;
	if (params->padding == 0)
	{
		i += ft_putstr_fd(padding, 1);
		i += ft_putstr_fd(to_print, 1);
	}
	else if (params->padding == 1)
	{
		i += ft_putstr_fd(to_print, 1);
		i += ft_putstr_fd(padding, 1);
	}
	return (i);
}

int			format_string(char *x, t_param *params)
{
	int		i;
	char	*padding;
	char	*to_print;

	i = 0;
	if (x == NULL)
		x = null_str();
	if (!(to_print = malloc(sizeof(*to_print) * (ft_strlen(x) + 1))))
		return (-1);
	if ((int)ft_strlen(x) > params->precision && params->precision >= 0)
		ft_strlcpy(to_print, x, params->precision + 1);
	else
		ft_strlcpy(to_print, x, ft_strlen(x) + 1);
	padding = create_padding(params->width - (int)ft_strlen(to_print), \
	params->zero);
	i += print_str(to_print, padding, params);
	free(padding);
	free(to_print);
	return (i);
}

int			format_char(char c, t_param *params)
{
	int		i;
	char	*padding;

	i = 0;
	padding = create_padding(params->width - 1, params->zero);
	if (params->padding == 0)
	{
		i += ft_putstr_fd(padding, 1);
		i += ft_putchar_fd(c, 1);
	}
	else if (params->padding == 1)
	{
		i += ft_putchar_fd(c, 1);
		i += ft_putstr_fd(padding, 1);
	}
	free(padding);
	return (i);
}

int			format_ptr(void *ptr, t_param *params)
{
	int		i;
	char	*padding;

	i = 0;
	padding = create_padding((params->width - \
	count_udigit((size_t)ptr, 16) - 2), params->zero);
	if (params->padding == 0)
	{
		i += ft_putstr_fd(padding, 1);
		i += ft_putstr_fd("0x", 1);
		i += ft_putxnbr_fd((size_t)ptr, 1, params->zero);
	}
	else if (params->padding == 1)
	{
		i += ft_putstr_fd("0x", 1);
		i += ft_putxnbr_fd((size_t)ptr, 1, params->zero);
		i += ft_putstr_fd(padding, 1);
	}
	free(padding);
	return (i);
}

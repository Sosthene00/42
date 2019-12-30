/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:29:57 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/30 20:20:01 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		is_type(char c)
{
	int 	i;
	char	*set;

	i = 0;
	set = "cspdiuxX%";
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	handle_ptr(va_list ap)
{
	void *ptr;
	int i;

	i = 0;
	if (!(ptr = va_arg(ap, void *)))
		return (0);
	i += ft_putstr_fd("0x", 1);
	return (i += ft_putxnbr_fd((size_t)ptr, 1, 0));
}

static int	print_out(va_list ap, char type)
{
	int i;

	i = 0;
	if (type == 's')
		i += (int)ft_putstr_fd(va_arg(ap, char *), 1);
	else if (type == '%')
		i += (int)ft_putstr_fd("%", 1);
	else if (type == 'd' || type == 'i')
		i += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (type == 'u')
		i += ft_putunbr_fd(va_arg(ap, size_t), 1);
	else if (type == 'x' || type == 'X')
		i += ft_putxnbr_fd(va_arg(ap, size_t), 1, (type == 'x') ? 0 : 1);
	else if (type == 'p')
		i += handle_ptr(ap);
	else if (type == 'c')
		i += (int)ft_putchar_fd(va_arg(ap, int), 1);
	return (i);
}

static get_arguments(char *fmt)
{
	t_arg	*list;

	list = ft_lstnew();
	
}

int	parser(char *fmt, va_list ap)
{
	char	type;
	size_t	i;

	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (is_type(*(++fmt)))
				type = *fmt++;
			else
				ft_putstr_fd("ERROR: non supported conversion", 2);
			i += print_out(ap, type);
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

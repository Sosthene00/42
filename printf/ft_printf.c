/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 13:25:02 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/06 15:42:29 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//TO_DO: handle type conversion from upper to lowercase
//TO_DO: 0 flag not compatible with c and p conversion

int ft_printf(const char *format, ...)
{
	int		res;
	va_list	ap;

	va_start(ap, format);
	if ((res = parser((char *)format, ap)) < 0)
		print_error(res);
	va_end(ap);
	return (res);
}

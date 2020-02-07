/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:29:04 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 14:38:52 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	handle_type(char type)
{
	char c;

	if (type == 'X')
		return (type);
	else
		c = ft_tolower(type);
	if (type == 'i')
		c = 'd';
	return (c);
}

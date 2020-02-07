/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:20:10 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/16 15:37:24 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	h_modifier(t_param *node, char *str)
{
	if (str[1] == 'h')
		return (node->len_modif = 2);
	else
		return (node->len_modif = 1);
}

int	l_modifier(t_param *node, char *str)
{
	if (str[1] == 'l')
	{
		node->len_modif = 4;
		return (2);
	}
	else
	{
		node->len_modif = 3;
		return (1);
	}
}

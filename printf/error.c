/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:32:24 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/08 16:01:47 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_error(int output)
{
	if (output == -1)
		ft_putstr_fd(INVALID_PARAMS, 2);
	if (output == -2)
		ft_putstr_fd(NULL_POINTER, 2);
}


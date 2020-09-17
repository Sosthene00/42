/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:52:21 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:52:26 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_warn	warnings[] =
{
	{ WRONG_ARG, "second argument can only be \"--save\"\n" },
	{ SCREEN_EXIST, "resolution already set, ignoring new values\n" },
	{ COLOR_EXIST, "color already exists, ignoring new values\n" },
	{ TEXTURE_EXIST, "texture already exists, ignoring new values\n" },
	{ RES_HIGH, "Resolution too high, setting to screen size\n"},
	{ RES_LOW, "Resolution can't be zero or negative, setting\n"},
	{ DEFAULT_WARN, "Unknown warning\n"},
};

static char	*catch_warn(t_warnid raised)
{
	int		i;

	i = 0;
	while (warnings[i].id != DEFAULT_WARN)
	{
		if (warnings[i].id == raised)
			return (warnings[i].msg);
		i++;
	}
	return ((char *)strerror(errno));
}

void	print_warning(t_warnid alert)
{
	char	*msg;

	msg = catch_warn(alert);
	ft_putstr_fd("Warning\n", 2);
	ft_putstr_fd(msg, 2);
}

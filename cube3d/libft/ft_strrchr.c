/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:18:49 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/14 14:46:16 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		d;
	const char	*last;

	d = c;
	last = NULL;
	while (*s)
	{
		if (*s == d)
			last = s;
		s++;
	}
	if (*s == d)
		last = s;
	return ((char *)last);
}

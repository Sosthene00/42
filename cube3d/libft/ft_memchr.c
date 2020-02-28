/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:26:43 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/16 19:50:55 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char				d;
	const		unsigned	char	*e;

	d = c;
	while (n-- > 0)
	{
		e = (const unsigned char *)s;
		if (*e == d)
			return ((void *)e);
		else
			s++;
	}
	return (NULL);
}

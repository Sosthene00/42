/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:53:07 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/14 14:31:58 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = c;
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == d)
			return ((char *)s);
		s++;
	}
	if (*s == d)
		return ((char *)s);
	return (NULL);
}

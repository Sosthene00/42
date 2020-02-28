/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:34:07 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/16 19:50:09 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;
	size_t	len;

	p = ft_memchr(src, c, n);
	if (p != NULL)
	{
		len = p - src + 1;
		dst = ft_memcpy(dst, src, len);
		return (dst + len);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}

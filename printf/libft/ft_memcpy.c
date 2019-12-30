/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:22:24 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/16 19:51:18 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*ptr;
	const		char	*s;

	ptr = dst;
	s = src;
	if (n != 0 && dst == 0 && src == 0)
		return (NULL);
	while (n-- > 0)
		*ptr++ = *s++;
	return (dst);
}

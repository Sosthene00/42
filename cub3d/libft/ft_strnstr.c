/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:31:07 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/16 19:53:42 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			haystack_len = ft_strlen(haystack);
			if (haystack_len < needle_len || needle_len > len)
				return (NULL);
			if (ft_memcmp(haystack, needle, needle_len) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}

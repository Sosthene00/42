/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:01:52 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/30 20:12:03 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s || (unsigned int)ft_strlen(s) <= start)
	{
		if (!(res = malloc(sizeof(*res) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (!(res = malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	ft_strlcpy(res, (char*)s + start, len + 1);
	return (res);
}

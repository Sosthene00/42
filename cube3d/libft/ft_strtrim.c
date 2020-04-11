/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:30:49 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/19 18:24:27 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		isinset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static	size_t	ltrim(char const *str, char const *set)
{
	size_t i;

	i = 0;
	while (isinset(str[i], set) == 1 && i < ft_strlen(str))
		i++;
	return (i);
}

static	size_t	rtrim(char const *str, char const *set)
{
	int     i;
	size_t  count;

	i = ft_strlen(str) - 1;
	count = 0;
	while (isinset(str[i], set) == 1 && i-- >= 0)
		count++;
	return (count);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	size;
	size_t	trim_count;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	trim_count = ltrim(s1, set);
	start = trim_count;
	if (size > trim_count)
		trim_count += rtrim(s1, set);
	size -= trim_count;
	if (!(trimmed = malloc(sizeof(*trimmed) * (size + 1))))
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, size + 1);
	return (trimmed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:32:26 by agaubert          #+#    #+#             */
/*   Updated: 2019/11/30 18:49:31 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_strlen_split(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static	size_t	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] == c)
		i++;
	if (str[i++] != c)
		count++;
	while (str[i])
	{
		if ((str[i - 1] == c || i == 0) && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_strdup_split(char const *str, char c)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen_split(str, c);
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	size_t	words;
	char	**strs;
	size_t	i;

	i = 0;
	strs = NULL;
	words = count_words(s, c);
	if (!(strs = malloc(sizeof(*strs) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			strs[i] = ft_strdup_split(s, c);
		while (*s && *s != c)
			s++;
		i++;
	}
	if (!(strs[i] = malloc(sizeof(char))))
		return (NULL);
	strs[i] = 0;
	return (strs);
}

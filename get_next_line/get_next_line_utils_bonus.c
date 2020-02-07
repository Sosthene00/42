/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:26:48 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/26 11:49:02 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_split(char const *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	free_mem(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*str;
	void	*to_free;

	i = 0;
	len = ft_strlen_split(s1, '\0') + ft_strlen_split(s2, '\0');
	to_free = s1;
	if (!(str = malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (s1 != NULL && *s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	free_mem(&to_free);
	return (str);
}

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

char	*ft_substr_mal(char *s, char c)
{
	void	*bgn;
	char	*res;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	bgn = s;
	if (*s == c)
		s++;
	else
	{
		while (*s && *s != c)
			s++;
		if (*s == c)
			s++;
	}
	if (!(res = malloc(sizeof(*res) * (ft_strlen_split(s, '\0') + 1))))
		return (NULL);
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	free_mem(&bgn);
	return (res);
}

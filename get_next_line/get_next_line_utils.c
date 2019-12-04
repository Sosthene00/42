/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:26:48 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/03 19:37:42 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen_split(char const *str, char c)
{
	int	i;

	i = 0;
	if (c == NULL)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != c)
			i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen_split(src);
	if (srclen + 1 < dstsize)
		len = srclen + 1;
	else if (dstsize != 0)
		len = dstsize - 1;
	else
		return (srclen);
	dst[len] = '\0';
	if (len != 0 && dst == 0 && src == 0)
		return (NULL);
	while (len-- > 0)
		*dst++ = *src++;
	return (srclen);
}

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

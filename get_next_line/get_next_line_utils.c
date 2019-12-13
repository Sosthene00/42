/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:26:48 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/11 20:08:07 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen_split(src, 0);
	if (srclen + 1 < dstsize)
		len = srclen + 1;
	else if (dstsize != 0)
		len = dstsize - 1;
	else
		return (srclen);
	dst[len] = '\0';
	if (len != 0 && dst == 0 && src == 0)
		return (srclen);
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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen_split(s, 0);
	write(fd, s, len);
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
		write(fd, "-2147483648\n", 12);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * -1;
		}
		if (n <= 9)
		{
			c = n + '0';
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*ptr;

	ptr = b;
	while (len-- > 0)
	{
		*ptr = c;
		ptr++;
	}
	return (b);
}

int     ft_strccpy_gnl(char *dst, char *src, char c)
{
    int i;

	dst = ft_strdup_split(src, c);
    i = ft_strlen_split(src, '\0') - (ft_strchr(src, (int)c) - src);
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*lasts;
	char		*lastd;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = dst;
	s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		lasts = (char *)s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}

char	*ft_strdup_split(char const *str, char c)
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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen_split(s1, '\0') + ft_strlen_split(s2, '\0');
	i = 0;
	if (s1 == NULL)
	{
		if (!(s1 = malloc(sizeof(*s1))))
			return (NULL);
		*s1 = '\0';
	}
	if (!(str = malloc(sizeof(*str) + (len + 1))))
		return (NULL);
	while (*s1)
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
	str[i] = 0;
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

char	*ft_substr_mal(char *s, unsigned int start)
{
	char	*temp;
	char	*res;
    int     i;

    i = 0;
	if (!s || (unsigned int)ft_strlen_split(s, '\0') <= start)
		return (NULL);
	if (!(temp = malloc(sizeof(*temp) * (ft_strlen_split(s, '\n') + 1))))
		return (NULL);
    while (s[i+start])
    {
        temp[i] = s[i+start];
        i++;
    }
    temp[i] = '\0';
    free(s);
	if (!(res = malloc(sizeof(*res) * (ft_strlen_split(temp, '\0') + 1))))
		return (NULL);
	res = ft_strdup_split(temp, '\0');
	return (res);
}

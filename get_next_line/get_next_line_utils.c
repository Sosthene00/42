/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:26:48 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/04 18:29:46 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_split(char const *str, char c)
{
	int	i;

	i = 0;
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

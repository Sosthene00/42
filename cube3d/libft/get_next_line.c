/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:13:34 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/26 11:48:43 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_mem(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_substr_free(char *s, char c)
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
	if (!(res = malloc(sizeof(*res) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[++i])
		res[i] = s[i];
	res[i] = '\0';
	free_mem(&bgn);
	return (res);
}

static char	*ft_strdup_split(char const *str, char c)
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

static int	do_line(ssize_t count, char **cur, char **line)
{
	if (count == 0 && (!(**cur) || !(ft_strchr(*cur, '\n'))))
	{
		if (!(*line = ft_strdup_split(*cur, '\n')))
			return (-1);
		free_mem((void *)cur);
		return (0);
	}
	if (!(*line = ft_strdup_split(*cur, '\n')))
		return (-1);
	if (!(*cur = ft_substr_free(*cur, '\n')))
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	ssize_t			count;
	char			buffer[BUFFER_SIZE + 1];
	static char		*cur[OPEN_MAX];

	count = 0;
	if ((read(fd, buffer, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		if (!(cur[fd] = ft_strjoin(cur[fd], buffer)))
			return (-1);
		if (ft_strchr(cur[fd], '\n'))
			break ;
	}
	if (cur[fd] == NULL)
	{
		if (!(cur[fd] = malloc(sizeof(*cur[fd]))))
			return (-1);
	}
	count = do_line(count, &cur[fd], line);
	return (count);
}

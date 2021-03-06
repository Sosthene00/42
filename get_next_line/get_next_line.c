/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:13:34 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/23 20:19:06 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (!(*cur = ft_substr_mal(*cur, '\n')))
		return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	ssize_t			count;
	char			buffer[BUFFER_SIZE + 1];
	static char		*cur;

	count = 0;
	if ((read(fd, buffer, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		if (!(cur = ft_strjoin(cur, buffer)))
			return (-1);
		if (ft_strchr(cur, '\n'))
			break ;
	}
	if (cur == NULL)
	{
		if (!(cur = malloc(sizeof(*cur))))
			return (-1);
	}
	count = do_line(count, &cur, line);
	return (count);
}

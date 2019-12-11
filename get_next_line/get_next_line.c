/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:13:34 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/11 20:40:58 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	ssize_t			count;
	//static t_list	*buf[OPEN_MAX];
	//t_list		*cur;
	char			buffer[BUFFER_SIZE + 1];
    static char		*cur;

	//printf("enter gnl\n");
	count = BUFFER_SIZE;
	//handle fd error, inexistent line, check array exist
	if ((read(fd, buffer, 0) < 0) || line == NULL)
	{
		ft_putstr_fd("ERROR: Can't read the file/no line to write to\n", 2);
		return (-1);
	}
    while (ft_strchr(cur, '\n') == NULL && (count = read(fd, ft_memset(buffer, '\0', BUFFER_SIZE + 1), BUFFER_SIZE)) > 0)
    {
		//printf("cur is %s\n", cur);
        cur = ft_strjoin(cur, buffer);
    }
    *line = ft_strdup_split(cur, '\n');
	cur = cur + ft_strlen_split(*line, '\0') + 1;
	if (*cur == '\0' && **line == '\0')
    {
		//printf("exit GNL\n");
        return (0);
    }
	//if no new line found before 
	//printf("exit GNL\n");
	return (1);
}

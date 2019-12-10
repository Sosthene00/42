/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:13:34 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/04 18:29:43 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*t_list	*ft_lstinit(void *content)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->newline = ft_memchr(node->content, '\n', BUFFER_SIZE);
	node->size = ft_strlen_split(node->content, '\n');
	node->next = NULL;
	return (node);
}
void	make_line(, char **line, char *newline)
{
	
}*/

int get_next_line(int fd, char **line)
{
	ssize_t			count;
	//static t_list	*buf[OPEN_MAX];
	//t_list			*cur;
	char			buffer[BUFFER_SIZE + 1];
    void            *newline;
    char            *cur;

	count = 0;
	//handle fd error, inexistent line, check array exist
	if (read(fd, buffer, 0) < 0)
	{
		ft_putstr_fd("ERROR: The file doesn't exist or is not readable for some reason\n", 2);
		return (-1);
	}
    while (newline == NULL)
    {
        count = read(fd, ft_memset(buffer, '\0', BUFFER_SIZE + 1), BUFFER_SIZE);
        newline = ft_memccpy(cur, buffer, '\n', count);
        cur = ft_strjoin(cur, cur + count);
        cur = cur + count;
    }
    //if (!(*line = malloc(sizeof(**line) * (ft_strlen_split(cur, '\n') + 1))))
    //    return (-1);
    *line = ft_strdup_split(cur, '\0');
    if (count == BUFFER_SIZE)
    {
        return (1);
    }
	//allocate memory for this file in the buf array
	/*if (!(cur = buf[fd]))
	{
		read(fd, buffer, BUFFER_SIZE);
		cur = ft_lstinit(buffer);
		*line = malloc(sizeof(**line) * cur->size);
		*line = cur->content;
	}*/
	//read file until EOF
	/*while ((count = read(fd, cur->content, BUFFER_SIZE)) > 0)
	{
		//if we have a NL in what we just read
		if ((cur->newline = ft_memchr(buf, '\n')) != NULL)
		{
			//feed the content of the buffer to a make_line function
			line = malloc(sizeof(*line) * ft_lstsize(buf));
			while (*buf)
			{
				*line = malloc(sizeof(**line) * buf->size);
				ft_strlcpy(*line, buf->content, buf->size);
				*line++;
				*buf++;
			}
			//return 1
			return (1);
		}
	}*/
	//if no new line found before 
	return (0);
}

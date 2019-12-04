/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:13:34 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/03 18:59:20 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstinit(void *content)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		node->content = NULL;
	else
		node->content = content;
	node->newline = ft_memchr(node->content, '\n');
	node->size = ft_strlen_split(node->content, '\n');
	node->next = NULL;
	return (node);
}
/*void	make_line(, char **line, char *newline)
{
	
}*/

void	print_struct(t_list	*node)
{
	ft_putstr_fd(node->content, 1);
	ft_putnbr_fd((int)node->size, 1);
	ft_putnbr_fd((int)node->newline, 1);
}

int get_next_line(int fd, char **line)
{
	ssize_t			count;
	static t_list	**buf;
	t_list			*cur;
	char			buffer[BUFFER_SIZE];

	count = 1;
	//handle fd error, inexistent line, check array exist
	if (fd < 0 || !(line) || !(buf + fd))
		return (-1);
	//allocate memory for this file in the buf array
	if (!(cur = (buf + fd)))
		read(fd, buffer, BUFFER_SIZE)
		cur = ft_lstinit(buffer);
	print_struct(cur);
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

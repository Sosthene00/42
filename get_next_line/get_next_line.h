/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:12:08 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/03 18:59:35 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <strings.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list
{
	char				*newline;
	t_list				*next;
	ssize_t				size; //(size_t)newline - (size_t)content
	char				*content;
}						t_list;

int get_next_line(int fd, char **line);

#endif

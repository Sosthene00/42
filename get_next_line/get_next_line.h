/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:12:08 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/23 17:50:54 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <strings.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);

size_t	ft_strlen_split(char const *str, char c);

char	*ft_strjoin(char *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

char	*ft_substr_mal(char *s, char c);

void	free_mem(void **ptr);

#endif

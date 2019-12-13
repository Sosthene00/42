/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:12:08 by agaubert          #+#    #+#             */
/*   Updated: 2019/12/13 15:50:49 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define EFILENONEX "The file doesn't exist"

# include <strings.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_list
{
	char				*newline;
	struct s_list		*next;
	ssize_t				size;
	char				*content;
}						t_list;

int		get_next_line(int fd, char **line);

void	*ft_memchr(const void *s, int c, size_t n);

size_t	ft_strlen_split(char const *str, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup_split(char const *str, char c);

char	*ft_strjoin(char *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

void	*ft_memmove(void *dst, const void *src, size_t len);

char	*ft_substr_mal(char *s, char c);

#endif

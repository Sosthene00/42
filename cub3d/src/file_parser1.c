/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:02:59 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/26 12:03:06 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_map(t_ctx *c, char *buf)
{
	char **map;
	char **bare_map;
	char *trimmed;

	if (!(trimmed = ft_strtrim(buf, "+")))
		return (NULL);
	if (!(bare_map = ft_split(trimmed, '+')))
		return (NULL);
	if (!(map = copy_map(c, bare_map)))
		return (NULL);
	free(trimmed);
	ft_freesplit(bare_map);
	return (map);
}

static char	*concatenate(char *buf, char *new)
{
	char	*temp;
	char	*res;
	size_t	len;

	if (new == NULL)
		return (buf);
	temp = ft_strdup(buf);
	free(buf);
	len = ft_strlen(temp) + ft_strlen(new) + 1;
	if (!(res = ft_calloc(len + 1, sizeof(*res))))
		return (NULL);
	if (!*temp)
		ft_strlcpy(res, new, len);
	else
		ft_strlcpy(res + ft_strlcpy(res, temp, len), new, len);
	res[len - 1] = SEP;
	free(temp);
	return (res);
}

static void	extract_map_from_file(t_ctx *c, char *line)
{
	char *buf;

	if (!(buf = ft_calloc(1, sizeof(*buf))))
		exit_program(c, 9);
	if (!(buf = concatenate(buf, line)))
		exit_program(c, 9);
	free(line);
	while (get_next_line(c->fd, &line) > 0)
	{
		if (!(is_map(line)))
		{
			free(line);
			if (buf[0] != 0)
				exit_program(c, 2);
			continue;
		}
		if (!(buf = concatenate(buf, line)))
			exit_program(c, 9);
		free(line);
	}
	if (!(buf = concatenate(buf, line)))
		exit_program(c, 9);
	c->map = get_map(c, buf);
	free(line);
	free(buf);
}

static char	*extract_params_from_file(t_ctx *c)
{
	char *line;
	char **items;

	while ((get_next_line(c->fd, &line) > 0) && !(is_map(line)))
	{
		if (ft_isalpha(line[0]))
		{
			items = ft_split(line, ' ');
			free(line);
			if (update_data(items, c) > 0)
			{
				ft_freesplit(items);
				exit_program(c, 2);
			}
			ft_freesplit(items);
		}
		else
			free(line);
	}
	if (is_complete(c) > 0)
		exit_program(c, 2);
	return (line);
}

int			parse_file(char *map_file, t_ctx *c)
{
	char *line;

	if ((c->fd = open(map_file, O_RDONLY)) < 0)
		exit_program(c, 2);
	line = extract_params_from_file(c);
	extract_map_from_file(c, line);
	if (close(c->fd) < 0)
		return (2);
	c->fd = 0;
	if (read_map(c) == 2)
		return (2);
	return (0);
}

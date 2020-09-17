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

static char	**get_map(char *buf)
{
	char **map;
	char *trimmed;

	if (!(trimmed = ft_strtrim(buf, "+")))
		return (NULL);
	if (!(map = ft_split(trimmed, '+')))
		return (NULL);
	free(trimmed);
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
		exit_program(c, MEMORY_ERROR);
	if (!(buf = concatenate(buf, line)))
		exit_program(c, MEMORY_ERROR);
	free(line);
	while (get_next_line(c->fd, &line) > 0)
	{
		if (!(is_map(line)))
		{
			free(line);
			if (buf[0] != 0)
				exit_program(c, MAP_ERROR);
			continue;
		}
		if (!(buf = concatenate(buf, line)))
			exit_program(c, MEMORY_ERROR);
		free(line);
	}
	if (!(buf = concatenate(buf, line)))
		exit_program(c, MEMORY_ERROR);
	c->map = get_map(buf);
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
				exit_program(c, INVALID_PARAM);
			}
			ft_freesplit(items);
		}
		else
			free(line);
	}
	if (is_complete(c) > 0)
		exit_program(c, MISSING_PARAM);
	return (line);
}

void		parse_file(char *map_file, t_ctx *c)
{
	char *line;

	if ((c->fd = open(map_file, O_RDONLY)) < 0)
		exit_program(c, WRONG_FILE);
	line = extract_params_from_file(c);
	extract_map_from_file(c, line);
	if (close(c->fd) < 0)
		exit_program(c, DEFAULT_ERROR);
	c->fd = 0;
	read_map(c);
}

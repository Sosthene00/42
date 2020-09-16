/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:45:53 by agaubert          #+#    #+#             */
/*   Updated: 2020/09/01 14:45:56 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(char *line)
{
	int walled;

	walled = 0;
	if (!(*line))
		return (0);
	while (*line)
	{
		if (!(ft_strchr("012 NSWE", *line)))
			return (0);
		if (*line == '1')
			walled = 1;
		line++;
	}
	if (walled == 0)
		return (0);
	return (1);
}

/*char	**copy_map(t_ctx *c, char **bare_map)
{
	char	**copy;
	int		x;

	x = -1;
	while (bare_map[++x])
	{
		if (ft_strlen(bare_map[x]) > (size_t)c->map_height)
			c->map_height = ft_strlen(bare_map[x]);
	}
	c->map_width = x;
	if (!(copy = ft_calloc(c->map_width + 3, sizeof(*copy))))
		exit_program(c, 9);
	if (!(copy[0] = ft_calloc(c->map_height, sizeof(**copy))))
		exit_program(c, 9);
	if (!(copy[c->map_width + 1] = ft_calloc(c->map_height, sizeof(**copy))))
		exit_program(c, 9);
	x = 0;
	while ((++x - 1) < c->map_width)
	{
		if (!(copy[x] = ft_strdup(bare_map[x - 1])))
			exit_program(c, 9);
	}
	copy[c->map_width + 2] = 0;
	return (copy);
}*/

void	follow_wall(char **map, t_ixy start, int x, int y)
{
	map[x][y] = '3';
	if (x == start.x && y == start.y)
		return ;
	if (map[x][y + 1] == '1')
		follow_wall(map, start, x, y + 1);
	if (y > 0 && (map[x][y - 1] == '1'))
		follow_wall(map, start, x, y - 1);
	if (x > 0 && map[x - 1][y] == '1')
		follow_wall(map, start, x - 1, y);
	if (map[x + 1] && map[x + 1][y] == '1')
		follow_wall(map, start, x + 1, y);
	if (map[x + 1] && map[x + 1][y + 1] == '1')
		follow_wall(map, start, x + 1, y + 1);
	if (y > 0 && x > 0 && (map[x - 1][y - 1] == '1'))
		follow_wall(map, start, x - 1, y - 1);
	if (x > 0 && map[x - 1][y + 1] == '1')
		follow_wall(map, start, x - 1, y + 1);
	if (map[x + 1] && y > 0 && map[x + 1][y - 1] == '1')
		follow_wall(map, start, x + 1, y - 1);
}

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

#include "cub3d_bonus.h"

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

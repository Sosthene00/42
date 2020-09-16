/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 09:57:43 by agaubert          #+#    #+#             */
/*   Updated: 2020/08/28 09:57:45 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		check_map_enclosure(char **map)
{
	t_ixy start;

	start.x = 0;
	start.y = 0;
	while (map[start.x])
	{
		while (map[start.x][start.y] && map[start.x][start.y] != '1')
			start.y++;
		if (map[start.x][start.y + 1] == '1' && map[start.x][start.y + 2] == '1'
			&& map[start.x + 1][start.y + 1] == '0')
			break ;
		start.x++;
		start.y = 0;
	}
	start.y++;
	follow_wall(map, start, start.x, start.y + 1);
	if (map[start.x][start.y - 1] == '3')
		return (0);
	return (2);
}

static	void	update_player(char dir, int x, int y, t_ctx *c)
{
	if ((c->player.pos.x + c->player.pos.y) > 0)
		exit_program(c, 2);
	c->player.pos.x = x;
	c->player.pos.y = y;
	if (dir == 'N')
	{
		c->player.dir.x = -1;
		c->player.plane.y = 0.66;
	}
	else if (dir == 'S')
	{
		c->player.dir.x = 1;
		c->player.plane.y = -0.66;
	}
	else if (dir == 'W')
	{
		c->player.dir.y = -1;
		c->player.plane.x = -0.66;
	}
	else if (dir == 'E')
	{
		c->player.dir.y = 1;
		c->player.plane.x = 0.66;
	}
}

static	int		read_line(char *line, int x, t_ctx *c)
{
	int y;

	y = 0;
	while (line[y])
	{
		if (line[y] == ' ' || line[y] == '0' ||
			line[y] == '1')
			;
		else if (ft_strchr(PLAYER_START, line[y]))
		{
			update_player(line[y], x, y, c);
			c->map[x][y] = '0';
		}
		else if (line[y] == '2')
			update_sprite(c, x, y);
		else
			return (2);
		y++;
	}
	if (y > c->map_height)
		c->map_height = y;
	return (0);
}

int				read_map(t_ctx *c)
{
	int x;
	int ret;

	x = 0;
	ret = 0;
	while (c->map[x])
	{
		if (read_line(c->map[x], x, c) == 2)
			exit_program(c, 2);
		x++;
	}
	if (check_map_enclosure(c->map) == 2 || c->player.pos.x == 0)
		ret = 2;
	return (ret);
}

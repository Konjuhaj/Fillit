/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/19 12:32:42 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	locate_space(t_map *mappi)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (mappi->map[++y])
	{
		while (mappi->map[y][++x])
		{
			if (mappi->map[y][x] == '.')
			{
				mappi->x = x;
				mappi->y = y;
				return (1);
			}
		}
	}
	return (1);
}

void	next_line(int i, int x, int y)
{
	i++;
	x = 0;
	y++;
}

void	find_block(char *str, int i)
{
	while (str[i] != '#')
		i++;
}
int		place_block(char *str, char **map, t_map *mappi)
{
	int i;
	int y;
	int x;

	i = -1;
	x = mappi->x;
	y = mappi->y;
	while (++i < 21)
	{
		while (str[i] != '#')
		{
			i++;
			if (str[i] == '\n')
				next_line(i, x, y);
		}

	}
}

int		solve(t_data *tetris, t_map *mappi)
{
	int i;

	i = 1;
	while (tetris->str)
		{
			if(!(locate_space(mappi->map)));
				create_map(tetris->n_hashes + i++);
			place_block(tetris->str, mappi->map, &mappi);
			tetris->str + 21;
		}
	return (0);
}

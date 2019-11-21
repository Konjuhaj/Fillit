/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/21 15:05:19 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	next_spot(t_map *mappi)
{
	while (mappi->map[mappi->y])
	{
		mappi->x++;
		while (mappi->map[mappi->y][mappi->x])
		{
			if (mappi->map[mappi->y][mappi->x] == '.')
				return (1);
			mappi->x++;
		}
		mappi->y++;
		mappi->x = -1;
	}
	return (0);
}

void	find_block(char *str, int i)
{
	while (str[i] != '#')
		i++;
}

void	add_block(char *str, t_map *mappi, char letter)
{
	int i;
	int x;
	int y;
	int count;

	count = 1;
	i = -1;
	x = mappi->x;
	y = mappi->y;
	mappi->map[y][x] = letter;
	while (++i < 20)
	{
		while (str[i] == '#')
		{
			if (str[i + 1] == '#')
			{
				i++;
				x++;
				count++;
			}
			else if (str[i + 5] == '#')
			{
				i +=5;
				y++;
				count++;
			}
			else if(str[i - 1] == '#')
			{
				i--;
				x--;
				count++;
			}
			mappi->map[y][x] = letter;
			if (count == 4)
				break ;
		}
	}
}
int		check_space(char *s, char **map, t_map *mappi)
{
	int i;
	int y;
	int x;
	int count;
	char *str;

	str= ft_strdup(s);
	count = 1;
	i = -1;
	x = mappi->x;
	y = mappi->y;
	while (++i < 20)
	{
		while (str[i] == '#')
		{
			if (x < mappi->map_size && str[i + 1] == '#' && map[y][x + 1] == '.')
			{
				str[i] = 'X';
				i++;
				x++;
				count++;
			}
			else if (map[y + 1] != NULL && str[i + 5] == '#' && map[y + 1][x] == '.')
			{
				str[i] = 'X';
				i +=5;
				y++;
				count++;
			}
			else if(str[i - 1] == '#' && map[y][x -1] == '.')
			{
				str[i] = 'X';
				i--;
				x--;
				count++;
			}
			else
				i++;
			if (count == 4)
				return(1);
		}
	}
	return (0);
}

int		solve(t_data *tetris, t_map *mappi)
{
	int i;
	size_t counter;
	unsigned long j;

	i = 1;
	j = 0;
	counter = 0;
	while (tetris->n_tetris)
	{
		if (check_space(tetris->str, mappi->map, mappi) == 1)
		{
			add_block (tetris->str, mappi, mappi->letter++);
			tetris->str += 21;
			tetris->n_tetris--;
			if (solve(tetris, mappi))
				return (1);
			tetris->n_tetris++;
			tetris->str -= 21;
			add_block (tetris->str, mappi, '.');

			if (next_spot(mappi) == 0 && tetris->n_tetris > 0)
			{
				return (0);
			}
		}
		else
		{
				ft_strdel(mappi->map);
				mappi->letter = 'A';
				mappi->x = 0;
				mappi->y = 0;
		}
	}
	print_map(mappi->map);
	return (1);
}

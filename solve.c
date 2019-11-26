/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/26 12:32:20 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		next_spot(t_map *mappi)
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

void	add_block(t_data *tetris, t_map *mappi, char letter, int xy[2])
{
	int		i;
	int		count;
	char	*str;

	count = 0;
	i = -1;
	str = ft_strsub(tetris->str, 0, 21);
	while (*str != '#')
		str++;
	while (++i < 20)
	{
		if (str[i] == '#')
			mappi->map[xy[1] + count][xy[0] + (i - (5 * count))] = letter;
		if (str[i] == '\n' && count < mappi->map_size)
			count++;
	}
}

int		check_block(t_data *tetris, t_map *mappi, int x, int y)
{
	int		i;
	int		count;
	int		num;
	char	*str;

	count = 0;
	i = 0;
	str = ft_strsub(tetris->str, 0, 21);
	num = 0;
	while (*str != '#')
		str++;
	while (*str)
	{
		if ((x + (i - (5 * count))) >= 0 && y + count < mappi->map_size - 1 &&
			*str == '#' && mappi->map[y + count][x + (i - (5 * count))] == '.')
			num++;
		if (*str == '\n' && count < mappi->map_size)
			count++;
		str++;
		i++;
	}
	if (num == 4)
		return (1);
	return (0);
}

void	update_info(t_map *mappi, t_data *tetris, int xy[2])
{
	mappi->x = xy[0];
	mappi->y = xy[1];
	mappi->letter--;
	tetris->n_tetris++;
	tetris->str -= 21;
}

int		solve(t_data *tetris, t_map *mappi)
{
	int xy[2];

	while (tetris->n_tetris)
	{
		if (next_spot(mappi) == 0 && tetris->n_tetris > 0)
			return (0);
		if (check_block(tetris, mappi, mappi->x, mappi->y))
		{
			xy[0] = mappi->x;
			xy[1] = mappi->y;
			mappi->x = -1;
			mappi->y = 0;
			add_block(tetris, mappi, mappi->letter++, xy);
			tetris->str += 21;
			tetris->n_tetris--;
			if (solve(tetris, mappi))
				return (1);
			update_info(mappi, tetris, xy);
			add_block(tetris, mappi, '.', xy);
		}
	}
	return (1);
}

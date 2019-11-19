/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/19 20:58:27 by bkonjuha         ###   ########.fr       */
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
			{
				return (1);
			}
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
int		place_block(char *str, char **map, t_map *mappi)
{
	int i;
	int y;
	int x;
	int count;

	count = 1;
	i = -1;
	x = mappi->x;
	y = mappi->y;
	while (++i < 21)
	{
		while (str[i] == '#')
		{
			mappi->map[y][x] = '#';
			printf("we's here\n");
			if (str[i + 1] == '#' && map[y][x + 1] == '.')
			{
				i++;
				x++;
				count++;
				mappi->map[y][x] = '#';
			}
			else if (str[i + 5] == '#' && map[y + 1][x] == '.')
			{
				i +=5;
				y++;
				count++;
				mappi->map[y][x] = '#';
			}
			else if(str[i - 1] == '#' && map[y][x -1] == '.')
			{
				i--;
				x--;
				count++;
				mappi->map[y][x] = '#';
			}
			if (count == 4)
				return(1);
		}
	}
	return (0);
}

int		solve(t_data *tetris, t_map *mappi)
{
	int i;
	unsigned long j;

	i = 1;
	j = 0;
	while (j <= tetris->len + 1)
		{
			printf("we're in the solve loop\n");
			if(!(place_block(tetris->str + j, mappi->map, mappi)))
			{
				printf("we'se here, but whatta do \n");
				if(!(next_spot(mappi)))
				{
					printf("inside of Next spot in Solve loop\n");
					ft_strdel(mappi->map);
					create_map(mappi->map_size + i++);
					j = 0;
				}
			}
			else
			{
				print_map(mappi->map);
				printf("found and placed block\n");
				next_spot(mappi);
				printf("is the hickup here \n");
				j += 21;
			}
		}
		printf("program says loop is done\n");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/20 11:19:05 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	next_spot(t_map *mappi)
{
	while (mappi->map[mappi->y])
	{
		mappi->x++;
		printf("current row is = %d\n", mappi->y);
		while (mappi->map[mappi->y][mappi->x])
		{
			printf("current collumn is = %d\n", mappi->x);
			if (mappi->map[mappi->y][mappi->x] == '.')
			{
				return (1);
			}
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

void	add_block(char *str, t_map *mappi)
{
	int i;
	int x;
	int y;

	i = -1;
	x = mappi->x;
	y = mappi->y;
	while (++i < 21)
	{
		printf("Ready steady\n");
		while (str[i] == '#')
		{
		mappi->map[y][x] = mappi->letter;
			if (str[i + 1] == '#' && mappi->map[y][x + 1] == '.')
			{
				printf("PLACING right >>>>\n");
				i++;
				x++;
			}
			else if (str[i + 5] == '#' && mappi->map[y + 1][x] == '.')
			{
				printf("PLACING down vvvv \n");
				i +=5;
				y++;
			}
			else if(str[i - 1] == '#' && mappi->map[y][x -1] == '.')
			{
				printf("PLACING left<<<< \n");
				i--;
				x--;
			}
			else
				i++;
		}
	}
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
			printf("we's here %d\n", i);
			if (str[i + 1] == '#' && map[y][x + 1] == '.')
			{
				printf("checking right >>>>\n");
				i++;
				x++;
				count++;
			}
			else if (str[i + 5] == '#' && map[y + 1][x] == '.')
			{
				printf("checking down vvvv COUNT(%d)\n", count);
				i +=5;
				y++;
				count++;
			}
			else if(str[i - 1] == '#' && map[y][x -1] == '.')
			{
				printf("checking left<<<< \n");
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
	unsigned long j;

	i = 1;
	j = 0;
	mappi->letter = 'A';
	while (j <= tetris->len + 1)
		{
			printf("we're in the solve loop\n");
			if(!(place_block(tetris->str + j, mappi->map, mappi)))
			{
				printf("we'se here, but whatta do \n");
				print_map(mappi->map);
				if(!(next_spot(mappi)))
				{
					printf("inside of Next spot in Solve loop\n");
					ft_strdel(mappi->map);
					create_map(mappi->map_size + i++);
					j = 0;
				}
				else
					solve(tetris, mappi);
			}
			else
			{
				printf("found and placed block\n");
				add_block(tetris->str + j, mappi);
				print_map(mappi->map);
				next_spot(mappi);
				printf("is the hickup here \n");
				j += 21;
				mappi->letter++;
			}
		}
		printf("program says loop is done\n");
	return (1);
}

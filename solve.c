/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:12:09 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/16 11:45:36 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	locate_space(t_map *mappi)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while(mappi->map[++i])
	{
		while(mappi->map[i][++j])
		{
			if (mappi->map[i][j] == '.')
				{
					mappi->y = i;
					mappi->x = j;
				}
		}
		j = -1;
	}
}

int		place_block(t_data *tetris, t_map *mappi)
{
	int i;
	int j;
	int k;

	i = mappi->y;
	j = mappi->x;
	k = 0;
	while(tetris->str[k] != '#')
		k++;
	while (mappi->map[i])
	{
		while (mappi->map[i][j])
		{
			if (mappi->map[i][j] != '.')
				return (-1);
			else if(tetris->str[k] != '#')
				k++;
			else
				mappi->map[i][j] = tetris->str[k++];
			j++;
			if (tetris->str[k] == '\n')
				break ;
		}
		i++;
	}
	// print_map(mappi->map);
	return (0);
}

int		solve(t_data *tetris, t_map *mappi)
{
	int i;

	i = -1;
	locate_space(mappi);
	place_block(tetris, mappi);
		// overlap();
		// add_block();
		// 	increase_letter();

	return (0);
}

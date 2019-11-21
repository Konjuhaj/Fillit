/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:11:58 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/21 11:21:45 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//Only for testing

int ft_square(int num, t_map *mappi)
{
	int i;

	i = 0;
	while (i * i < num)
		i++;
	mappi->map_size = i;
	return (i);
}

char	**create_map(int size)
{
	char **mappi;
	int i;

	i = -1;
	mappi = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		mappi[i] = (char *)malloc(sizeof(char) * (size + 1));
		mappi[i][size] = '\0';
	}
	mappi[size] = NULL;
	i = -1;
	while(mappi[++i])
		ft_memset(mappi[i], '.', size);
	return (mappi);
}

void	print_map(char **map)
{
	int i;

	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

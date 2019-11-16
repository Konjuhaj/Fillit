/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:11:58 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/16 11:57:08 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//Only for testing

int ft_square(int num)
{
	int i;

	i = 0;
	while (i * i <= num)
		i++;
	printf("And the square shall be = %d\n", i);
	return (i);
}

char	**create_map(int size)
{
	printf("Creating the map\n");
	char **mappi;
	int i;

	i = -1;
	mappi = (char **)malloc(sizeof(char *) * (size + 1));
	printf("successfull malloc\n");
	while (++i < size)
	{
		mappi[i] = (char *)malloc(sizeof(char) * (size + 1));
		mappi[i][size] = '\0';
	}
	printf("outside loop\n");
	i = -1;
	while(mappi[++i])
		ft_memset(mappi, '.', size);
	printf("memset done\n");
	mappi[size] = NULL;
	printf("something s\n");
	print_map(mappi, size);
	printf("end of map creationg\n");
	return (mappi);
}

void	print_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		printf("a\n");
		j = 0;
		while (j < size)
		{
			printf("b\n");
			write(1, &map[i][j], size);
			printf("\nc\n");
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
// {
// 	printf("printing called\n");
// 	int i;

// 	i = -1;
// 	while(map[++i])
// 		ft_putstr(map[i]);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:11:58 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/16 09:54:56 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_map(t_data *tetris, int size)
{
	char **map;
	int i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		map[i][size] = '\0';
	}
	map[size] = NULL;
	return (map);
}

void		print_map(char **map)
{
	int i;

	i = -1;
	while(map[++i])
		ft_putstr(map[i]);
}

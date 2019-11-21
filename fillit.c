/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:56:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/21 11:51:13 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //only used for testting

/*
** FUNCTION ERRNO
** Can be used to print out error messages at any point of the program.
** Easiest way to call it is to put it in a return statement. I.e return(errno(1));
*/

int		errno(void)
{
	ft_putstr("error\n");
	return (-1);
}

char	*please_read(int fd)
{
	char buff[BUFF_SIZE + 1];
	char *temp;
	char *str;
	int ret;

	str = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE))) // same while loop as in gnl
	{
		buff[ret] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str, buff);
			free(str);
			str = temp;
		}
	}
	return (str);
}

int		main(int ac, char **av)
{
	size_t mover;
	t_data tetris;
	int fd;
	t_map mappi;

	if (ac != 2)
		write(1, "usage: ./fillit file_name\n", 26);
	else
	{
		fd = open(av[1], O_RDONLY);
		tetris.str = please_read(fd);
		tetris.len = ft_strlen(tetris.str);
		mover = 0;
		if ((validate_square(&tetris) == 0))
		{
			while (mover <= tetris.len)
			{
				if ((check_shapes(tetris.str + mover, &tetris) != 0))
					return (errno());
				mover += 21;
			}
			mappi.map = create_map(ft_square(tetris.n_hashes, &mappi));
			mappi.y = 0;
			mappi.x = 0;
			mappi.letter = 'A';
			solve(&tetris, &mappi);
		}
		else
			return (errno());
	}
	return (0);
}

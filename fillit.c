/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:56:54 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/15 11:13:08 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> //only used for testting

/*
** FUNCTION VALIDATE SQUARE
** vvv Checks for the following things vvv
** correct amount of #
** correct amount of lines
** correct amount of boxes
** correct amount of new lines between boxes and at the end of the file
** anything else than '.' | '#' | '\n'
**
** DOES NOT CHECK TETRINOME SHAPE
**
** a line has 5 characters including the new line
** a box has 20 charachyers including a new line
** boxes are seperated by a new line. Thus a valid box is 21 characters (3 x 4 x '.', 4 x '#', 4 x '\n' + separator)
** The above formula is always true except for the last box. That is why we add + 1 in the if statement outside the loop
**
*/

int	validate_square(char *str, size_t len)
{
	size_t count; //Counting the amount of hastags
	size_t num; //Counting the amount of tetrinoms
	size_t i;
	size_t limit;

	count = 0;
	num = 0;
	i = - 1;
	limit = 19;
	while (str[++i] != '\0')
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n') //checking for other characters
			return(-1);
		if (str[i] == '#')
			count++;
		if (i == limit && str[i] == '\n' && count % 4 == 0)//boxes are 20 characters long meaning at index 19 should be a /n and ther should have been 4x '#'
		{
			limit += 21;
			num++;
			if (i < len - 1)
				i++;
		}
	}
	if (num != ((len + 1) / 21) || ((len + 1) % 21) != 0) //for every tetrinome there should be 21 characters (except the last one) len + 1 should also be either 21, 42, 63.. and so on.
		return (-1);
	return (0);
}

/*
** FUNCTION ERRNO
** Can be used to print out error messages at any point of the program.
** Easiest way to call it is to put it in a return statement. I.e return(errno(1));
*/

int		errno(int n)
{
	if (n == 1)
	{
		ft_putstr("Too few arguments");
		return (0);
	}
	else if (n > 2)
	{
		ft_putstr("Too many arguments");
		return (0);
	}
	else if (n == -1)
		ft_putstr("error");
	return (-1);
}

char	*please_read(char *s)
{
	int fd;
	int ret;
	char *temp;
	char buff[BUFF_SIZE + 1];
	char *str2;

	fd = open(s, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE))) // same while loop as in gnl
	{
		buff[ret] = '\0';
		if (!str2)
			str2 = ft_strdup(buff);
		else
			temp = ft_strjoin(str2, buff);
			free(str2);
			str2 = temp;
	}
	return (str2);
}
int		main(int ac, char **av)
{
	size_t mover;
	size_t len;
	char *str;

	str = ft_strnew(1);
	if (ac != 2)
		return(errno(ac));
	else
	{
		str = please_read(av[1]);
		len = ft_strlen(str);
		mover = 20;
		if ((validate_square(str, ft_strlen(str)) == 0))
		{
			while (mover <= len)
			{
				if ((checkvalid(str + mover, 21) != 0))
					return (errno(-1));
				mover += 21;
			}
			ft_putstr("valid square\n");
		}
		else
		{
			ft_putstr("not a valid square\n");
		}

	}
	return (0);
}

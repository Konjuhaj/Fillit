/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkshapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:06:15 by msuarez-          #+#    #+#             */
/*   Updated: 2019/11/21 15:14:46 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>//For testing only

int	check_shapes(char *str, t_data *tetris)
{
	int count;

	tetris->i = -1;
	count = 0;
	while (++tetris->i < 21)
	{
		if (str[tetris->i] == '#')
		{
			if (tetris->i > 0 && str[tetris->i - 1] == '#')//check left
				count++;
			if (tetris->i > 4 && str[tetris->i - 5] == '#')//check above
				count++;
			if (tetris->i < 21 && str[tetris->i + 1] == '#')//check right
				count++;
			if (tetris->i < 21 -4 && str[tetris->i + 5] == '#')//check below
				count++;
		}
	}
	if (count != 8 && count != 6)
		return (-1);
	return (0);
}

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
** a box has 20 characters including a new line
** boxes are separated by a new line. Thus a valid box is 21 characters (3 x 4 x '.', 4 x '#', 4 x '\n' + separator)
** The above formula is always true except for the last box. That is why we add + 1 in the if statement outside the loop
*/

int	validate_square(t_data *tetris)
{
	size_t	limit;

	tetris->n_hashes = 0;
	tetris->n_tetris = 0;
	tetris->i = - 1;
	limit = 19;
	while (tetris->str[++tetris->i] != '\0')
	{
		if (tetris->str[tetris->i] != '#' && tetris->str[tetris->i] !='.'
		&& tetris->str[tetris->i] != '\n') //checking for other characters
			return(-1);
		if (tetris->i == 19 && (tetris->str[tetris->i + 1] == '.' || tetris->str[tetris->i + 1] == '#'))
			return(-1);
		if (tetris->str[tetris->i] == '#')
			tetris->n_hashes++;
		if (tetris->i == limit  && tetris->str[tetris->i] == '\n' && tetris->n_hashes % 4 == 0) //boxes are 20 characters long meaning at index 19 should be a /n and there should have been 4x '#'
		{
			tetris->n_tetris++;
			limit += 21;
			if (tetris->i + 1 != tetris->len)
				tetris->i++;
		}
	}
	if (tetris->n_tetris != ((tetris->len + 1) / 21) || ((tetris->len + 1) % 21) != 0 ||
	tetris->n_hashes % 4 != 0 || tetris->n_hashes / 4 != tetris->n_tetris) //for every tetrinome there should be 21 characters (except the last one) len + 1 should also be either 21, 42, 63.. and so on.
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:37:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/15 10:55:39 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkvalid(char *str, size_t len)
{
	size_t i;
	int count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		if (str[i] == '#')
		{
			if (i > 0 && str[i - 1] == '#')//check left
				count++;
			if (i > 4 && str[i - 5] == '#')//check above
				count++;
			if (i < len && str[i + 1] == '#')//check right
				count++;
			if (i < len -4 && str[i + 5] == '#')//check below
				count++;
		}
	}
	ft_putnbr(count);
	ft_putchar('\n');
	if (count != 8 && count != 6)
		return (-1);
	return (0);
}

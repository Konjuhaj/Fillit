/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:55:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/15 11:10:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include "libft/libft.h"

int		checkvalid(char *str, size_t len);

int		errno(int n);

int		validate_square(char *str, size_t len);

char	*please_read(char *s);

#endif

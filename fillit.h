/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:55:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/16 11:53:43 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_data
{
	size_t		n_hashes;
	size_t		n_tetris;
	size_t		len;
	size_t		i;
	char		*str;
}				t_data;

typedef struct s_map
{
	int			x;
	int			y;
	char		**map;
	char		letter;
}				t_map;

int				check_shapes(char *str, t_data *tetris);

char			*please_read(int fd);

int				errno(void);

int				validate_square(t_data *tetris);

void			print_map(char **map, int size);

char			**create_map(int size);

int				solve(t_data *tetris, t_map *mappi);

int				place_block(t_data *tetris, t_map *mappi);

void			locate_space(t_map *mappi);

int				ft_square(int num);

#endif

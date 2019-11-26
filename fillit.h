/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:55:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/11/26 10:25:15 by bkonjuha         ###   ########.fr       */
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

typedef struct	s_map
{
	int			map_size;
	int			x;
	int			y;
	int			remember[2];
	char		**map;
	char		letter;
}				t_map;

int				check_shapes(char *str, t_data *tetris);

char			*please_read(int fd);

int				errno(void);

int				validate_square(t_data *tetris);

void			print_map(char **map);

char			**create_map(int size);

int				solve(t_data *tetris, t_map *mappi);

int				check_space(t_data *tetris, t_map *mappi);

int				locate_space(t_map *mappi);

int				ft_square(int num, t_map *mappi);

void			reset_map(t_map *mappi, int i);

int				check_hard(t_map *mappi, t_data *tetris);

#endif

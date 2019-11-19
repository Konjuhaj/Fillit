# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 17:56:51 by msuarez-          #+#    #+#              #
#    Updated: 2019/11/18 18:54:51 by msuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c map.c solve.c checkshapes.c

OBJECTS = $(subst .c,.o,$(SRC))

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		@gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
		@/bin/rm -f $(OBJECTS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

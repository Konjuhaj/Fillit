
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 17:56:51 by msuarez-          #+#    #+#              #
#    Updated: 2019/11/25 14:03:04 by bkonjuha         ###   ########.fr        #
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
		@make -C libft/
		@gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
		@/bin/rm -f libft/*.o
		@/bin/rm -f $(OBJECTS)

fclean: clean
		@/bin/rm -f $(LIBFT)
		@/bin/rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 00:56:24 by mlambert          #+#    #+#              #
#    Updated: 2017/06/30 19:21:14 by mlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in.a

SRCS = lem_in.c init.c links.c errors.c path_carving.c solve.c room.c \
	get_next_line.c the_march.c

OBJ = $(SRCS:.c=.o)

LIB = ft_printf/libftprintf.a

all:$(NAME)

$(NAME):
	make -C ft_printf/
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) $(LIB)

clean:
	make -C ft_printf/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

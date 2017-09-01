# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 17:43:48 by mlambert          #+#    #+#              #
#    Updated: 2017/04/13 15:54:52 by mlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c type_hex.c hexx.c ft_ramification.c ft_oo_lrg.c ft_oo_prc.c \
	ft_hex_prc.c ft_hex_lrg.c ft_di_prc.c ft_di_lrg.c type_intodu.c	\
	ft_itoa_base.c type_str.c type_char.c modulo.c ft_u_prc.c uintoa.c jzed.c \
	ft_u_lrg.c type_p.c	unicode.c uni_uni.c init.c greffe.c

LPATH = libft_kek/

LSRC = 	ft_strlen.c	ft_strdup.c	ft_strcpy.c ft_strncpy.c				\
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c				\
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c			 	\
		ft_strncmp.c ft_strnew.c ft_strdel.c ft_strclr.c				\
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c				\
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c				\
		ft_strtrim.c ft_strsplit.c										\
																		\
		ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c				\
		ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c				\
																		\
		ft_bzero.c ft_isalpha.c ft_isdigit.c ft_isalnum.c				\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c				\
																		\
		ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c			\
		ft_putnbr.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c			\
																		\
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c				\
		ft_lstiter.c ft_lstmap.c										\
																		\
		ft_atoi.c ft_itoa.c												\
																		\
		ft_range.c ft_strnjoin.c ft_strndup.c ft_power.c				\
		ft_sqrt.c ft_lstlen.c ft_words.c								\

OBJ = $(SRC:.c=.o)

LOBJ = $(LSRC:.c=.o)

all:$(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) $(addprefix ${LPATH}, $(LSRC)) \
		-Ilibft_kek/
	@ar rc $(NAME) $(LOBJ) $(OBJ)
	@ranlib $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(LOBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re

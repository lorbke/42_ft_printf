# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:03:56 by lorbke            #+#    #+#              #
#    Updated: 2022/08/29 15:44:56 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc #-Wall -Wextra -Werror

SRC = ft_printf.c ft_parse.c ft_vector.c ft_vector_helper.c ft_itoa_base.c \
ft_printstr.c ft_printchar.c ft_strlen.c ft_strchr.c \
ft_memmove.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	@$(CC) -c $< -o $@

$(NAME): $(OBJ)
	@ar cr $(NAME) $(OBJ)

bonus: re

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

test: re
	@$(CC) test.c $(OBJ)
	@./a.out | cat -e

re: fclean all

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduban <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 12:05:34 by aduban            #+#    #+#              #
#    Updated: 2015/04/02 18:01:44 by aduban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computor

SRC = comp.c\
	  utils.c \
	  simplify.c \
	  init.c \
	  display.c \

.PHONY: libft.a

OBJ = $(SRC:.c=.o)

all : libft.a $(NAME)

libft.a:
		@$(MAKE) -C ./libft

$(NAME) : $(OBJ)
		@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) -L./libft/ -lftprintf -I ./libft

%.o: %.c
		@gcc -Wall -Werror -Wextra -I./libft/ -o $@ -c $^

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

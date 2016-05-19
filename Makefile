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

NAME = abstractvm

SRC = main.cpp\
	  Exception.cpp \
	  Factory.cpp \
	  Operand.cpp \
	  Stack.cpp \


all :  $(NAME)

$(NAME) :
		@g++ -Wall -Werror -Wextra -o $(NAME) -std=c++11 *.cpp -lboost_regex

clean :
		rm -f $(NAME)

fclean : clean
		rm -f $(NAME)

re : fclean all

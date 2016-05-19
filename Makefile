# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aduban <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 12:05:34 by aduban            #+#    #+#              #
#    Updated: 2016/05/19 17:01:48 by aduban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstractvm

SRC = main.cpp\
	  Exception.cpp \
	  Factory.cpp \
	  Operand.cpp \
	  Stack.cpp \

OBJ = $(SRC:.cpp=.o)

all :  $(NAME)

$(NAME) : $(OBJ)
		@g++ -Wall -Werror -Wextra -std=c++11  $(OBJ) -o $(NAME) -I /nfs/2014/a/aduban/.brew/Cellar/boost/1.60.0_2/include -L/nfs/2014/a/aduban/.brew/Cellar/boost/1.60.0_2/lib -lboost_regex

%.o: %.cpp
		@g++ -Wall -Werror -Wextra -std=c++11 -I /nfs/2014/a/aduban/.brew/Cellar/boost/1.60.0_2/include  -c $^


clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

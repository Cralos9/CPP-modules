# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 12:34:21 by cacarval          #+#    #+#              #
#    Updated: 2024/08/08 12:39:58 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

SRCS = main.cpp BitcoinExchange.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME) : $(OBJS)
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re: fclean all
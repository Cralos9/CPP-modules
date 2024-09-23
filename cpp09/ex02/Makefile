# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 12:05:13 by cacarval          #+#    #+#              #
#    Updated: 2024/08/28 12:43:05 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

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
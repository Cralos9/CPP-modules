# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:46:13 by cacarval          #+#    #+#              #
#    Updated: 2024/08/12 12:46:23 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRCS = main.cpp RPN.cpp

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
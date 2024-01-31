# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:57:51 by cacarval          #+#    #+#              #
#    Updated: 2024/01/31 11:59:59 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRCS = ClapTrap.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME): ${OBJS}
	c++ ${CPPFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all
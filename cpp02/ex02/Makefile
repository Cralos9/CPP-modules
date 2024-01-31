# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:40:07 by cacarval          #+#    #+#              #
#    Updated: 2024/01/30 10:56:58 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS = main.cpp Fixed.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

$(NAME) : ${OBJS}
		c++ ${CPPFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all

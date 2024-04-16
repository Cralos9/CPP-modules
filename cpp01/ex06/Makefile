# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:18:06 by cacarval          #+#    #+#              #
#    Updated: 2024/04/11 13:09:07 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = Harl.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

$(NAME): ${OBJS}
	 	c++ ${CXXFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.SILENT:

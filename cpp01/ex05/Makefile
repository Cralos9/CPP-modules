# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 15:18:06 by cacarval          #+#    #+#              #
#    Updated: 2024/01/29 10:24:44 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

SRCS = Harl.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

$(NAME): ${OBJS}
	 	c++ ${CPPFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.SILENT:
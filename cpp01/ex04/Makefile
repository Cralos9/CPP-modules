# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:48:22 by cacarval          #+#    #+#              #
#    Updated: 2024/01/24 15:16:21 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

$(NAME): ${OBJS}
		c++ ${CPPFLAGS} ${OBJS} -o ${NAME}
		@echo ${NAME}" was created"
all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	@echo ${NAME}" was deleted"

re: fclean all

.SILENT:
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 12:20:03 by cacarval          #+#    #+#              #
#    Updated: 2024/04/16 12:39:46 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

SRCS = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}
GREEN := \e[1;32m
RED := \e[1;31m
RESET := \033[0m

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME): ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN}materia file was created ${RESET}"

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all

.SILENT:
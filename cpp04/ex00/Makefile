# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:57:51 by cacarval          #+#    #+#              #
#    Updated: 2024/05/02 10:47:33 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal

SRCS = Animal.cpp main.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp

OBJS = ${SRCS:.cpp=.o}
GREEN := \e[1;32m
RED := \e[1;31m
RESET := \033[0m

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

$(NAME): ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN}Animal file was created ${RESET}"

all : ${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re: fclean all

.SILENT:
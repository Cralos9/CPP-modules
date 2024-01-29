# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 10:56:12 by cacarval          #+#    #+#              #
#    Updated: 2024/01/24 11:59:11 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = weapons

SRCS = HumanA.cpp main.cpp Weapon.cpp HumanB.cpp
OBJS = ${SRCS:.cpp=.o}
CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98
GREEN := \e[1;32m
RED := \e[1;31m
RESET := \033[0m

$(NAME): ${OBJS}
	c++ ${CPPFLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN}"$(NAME)" was created ${RESET}"

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		@echo "${RED}"$(NAME)" was deleted ${RESET}"

re : fclean all

.SILENT:
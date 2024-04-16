# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 11:29:25 by cacarval          #+#    #+#              #
#    Updated: 2024/01/17 12:30:04 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98
GREEN := \033[32m
RED := \033[31m
RESET := \033[0m

NAME = megaphone

all: ${NAME}

${NAME}:
	c++ ${CFLAGS} megaphone.cpp -o ${NAME}
	@echo "${GREEN}megaphone is ready${RESET}"

fclean:
	rm -f ${NAME}
	@echo "${RED}megaphone was removed${RESET}"

re: fclean all

.SILENT:

.PHONY: all fclean re

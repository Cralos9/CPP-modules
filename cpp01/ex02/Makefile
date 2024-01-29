# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 11:36:15 by cacarval          #+#    #+#              #
#    Updated: 2024/01/23 10:40:23 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain
CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

$(NAME):
		c++ ${CPPFLAGS} main.cpp -o ${NAME}

all:    ${NAME}

fclean: 
	rm brain

re : fclean all

.PHONY: all fclean re


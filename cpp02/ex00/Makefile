# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacarval <cacarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 10:40:07 by cacarval          #+#    #+#              #
#    Updated: 2024/04/15 13:23:29 by cacarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

NAME = a.out
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
OBJS = $(SRC:.cpp=.o)
SRC = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)Executable ./$(NAME) was created.\n$(RESET)"

clean:
	@$(RM) $(OBJS)
	printf "$(YELLOW)Object files were removed.\n$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	printf "$(RED)Executable ./$(NAME) was removed.\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:

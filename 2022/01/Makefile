# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jaberkro <jaberkro@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/03 16:32:09 by jaberkro      #+#    #+#                  #
#    Updated: 2022/12/05 21:16:10 by jaberkro      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = calories
SRC = part1+2.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	c++ $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:40:49 by jeluiz4           #+#    #+#              #
#    Updated: 2022/12/18 15:43:43 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c

FLAGS = -Wall -Wextra -Werror -g

all:
	cc $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:40:49 by jeluiz4           #+#    #+#              #
#    Updated: 2023/01/08 20:03:43 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main.c \
		modlib.c \
		ignite.c \
		routine.c \
		time.c

FLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=address

all:
	cc $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean

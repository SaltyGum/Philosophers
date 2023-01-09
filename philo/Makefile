# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:40:49 by jeluiz4           #+#    #+#              #
#    Updated: 2023/01/08 22:21:12 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main.c \
		modlib.c \
		ignite.c \
		routine.c \
		time.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=address

all: $(NAME)

$(NAME):
	cc $(FLAGS) $(SRCS) -c
	cc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean

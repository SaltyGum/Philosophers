# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeluiz4 <jeffluiz97@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 15:40:49 by jeluiz4           #+#    #+#              #
#    Updated: 2023/01/19 17:46:55 by jeluiz4          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	drop_fork.c \
		ignite.c \
		ignite_utils.c \
		main.c \
		modlib.c \
		pick_fork.c \
		route.c \
		routine.c \
		time.c \
		waiter.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=address,undefined

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
